/*********************************************************************************
* Copyright (c) 2014 David D. Marshall <ddmarsha@calpoly.edu>
*
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
*    David D. Marshall - initial code and implementation
********************************************************************************/

#ifndef eli_geom_curve_pseudo_four_digit_mod_thickness_hpp
#define eli_geom_curve_pseudo_four_digit_mod_thickness_hpp

#include <string>    // std::string
#include <sstream>   // std::ostringstream, std::istringstream
#include <iomanip>   // std::setw
#include <algorithm> // std::transform

#include "eli/code_eli.hpp"
#include "eli/geom/curve/pseudo/naca_af.hpp"

namespace eli
{
  namespace geom
  {
    namespace curve
    {
      namespace pseudo
      {
        template<typename data__>
        class four_digit_mod_thickness : virtual public naca_af<data__> {
        public:
            typedef naca_af<data__> base_class_type;
            typedef typename base_class_type::data_type data_type;
            typedef typename base_class_type::point_type point_type;
            typedef typename base_class_type::coefficient_type coefficient_type;
            typedef typename base_class_type::index_type index_type;
            typedef typename base_class_type::complex_data_type complex_data_type;

          public:

            coefficient_type get_thickness_coefficients_front() const {return a;}


            // Valid values of thickness location greater than 0 and less than 100
            bool set_thickness_loc(const data_type &t_loc)
            {
                if ((t_loc>=.2) && (t_loc<=.6))
                {
                    thickness_loc=t_loc;
                    return true;
                }
                return false;
            }
            data_type get_maximum_thickness_location() const {return thickness_loc;}

            // Valid values of le radius index are greater than 0 and less than 8
            bool set_leradindex(const data_type &lei)
            {
                if ((lei>=0) && (lei<=9))
                {
                    le_radius_indx=lei;
                    recalc_thickness_coefficients();
                    return true;
                }
                return false;
            }
            data_type get_leradindex() const {return le_radius_indx;}

          protected:

            void recalc_thickness_coefficients()
            {
              // Calculate 4-digit modified curve coefficients for 20% thick airfoil
              // With given maximum thickness position and leading edge radius index.
              // Flag for sharp or 'thick' trailing edge.

              data_type a0, a1, a2, a3;
              data_type d0, d1, d2, d3;

              data_type tocref = 0.2;

              data_type mt = thickness_loc;

              data_type xmtsq = mt * mt;
              data_type xmtcu = xmtsq * mt;
              data_type srxmt = sqrt( mt );

              data_type rle = ( 1.1019 / 36.0 ) * tocref * tocref * le_radius_indx * le_radius_indx;

              if ( le_radius_indx > 8.0 )
              {
                  data_type rle8 = ( 1.1019 / 36.0 ) * tocref * tocref * 64.0; // Quadratic up to index of 8
                  data_type rle9 = ( 1.1019 ) * tocref * tocref * 3.0;         // Three times normal radius.

                  // Linear interpolation of radius between index 8 and 9.
                  data_type di = le_radius_indx - 8.0;
                  data_type drle = rle9 - rle8;
                  rle = rle8 + di * drle;
              }

              if ( !this->sharp_trailing_edge() ) // 'Official' airfoil has TE semi-bluntness of 1% of thickness.
              {
                  d0 = 0.01 * tocref;
              }
              else
              {
                  d0 = 0.0;
              }

              // The 'official' definition of modified airfoils only exists at five locations of maximum thickness.
              // The d1 coefficient is tabulated at these five points.
              //
              //   m     d1   Riegels  Current
              //  0.2  0.200  0.19990  0.20025
              //  0.3  0.234  0.23364  0.23312
              //  0.4  0.315  0.31442  0.31609
              //  0.5  0.465  0.46434  0.46439
              //  0.6  0.700  0.72189  0.70012
              //
              // Riegels developed an approximate equation that allows continuous variation of the maximum thickness
              // location over the same range.  Riegels' equation has been used (uncited) in NASA published computer
              // programs and reports (TM X 3284 and TM 4741) for generating the NACA modified thickness forms.  It is
              // identified by name in Bill Mason's course notes on airfoil geometry.  Ralph Carmichael distributes
              // an airfoil generating program via PDAS that uses a polynomial fit as an improvement over Riegels.
              //
              // Considerable effort was extended on developing an improved approximation with the hopes of enabling
              // airfoils with maximum thickness location beyond the [0.2, 0.6] range.  Those efforts ultimately proved
              // unsuccessful at generating reasonable airfoils over the extended range -- it appears that the d1
              // coefficient was not the problem.
              //
              // A Matlab program was written to find the nonlinear least squares best fit to Riegels equation.  This
              // optimal sef of coefficients is used here.
              //
              // Riegels equation.
              // d1 = ( 0.1 * ( 2.24 - 5.42 * mt + 12.3 * xmtsq ) / ( 1.0 - 0.878 * mt ) );
              //
              // Riegels, F. W., "Aerofoil Sections, Results from Wind-Tunnel Investigations, Theoretical Foundations",
              // Translated from the German by D. G. Randall, Butterworths, London, 1961.

              // Best fit to Riegels form
              data_type c1, c2, c3, c4, c5;
              c1 =  0.244364095382286;
              c2 = -0.677199764201376;
              c3 =  1.609809719636767;
              c4 = -0.672612098884539;
              d1 = ( c1 + c2 * mt + c3 * xmtsq ) / ( 1.0 + c4 * mt );

              // With d1 (which determines trailing edge angle) determined by the location of the maximum thickness, and
              // a0 determined by the leading edge radius, the geometric constraints of C2 matching at the max thickness
              // point is enough to set all the remaining coefficients.  These equations had to be re-derived to work
              // for non-default values of the TE thickness.  This also allows for more precision.

              /*
              Maxima computer algebra commands to derive airfoil coefficients.

              set_display('none)$
              yr(x):=d0+d1*(1-x)+d2*(1-x)^2+d3*(1-x)^3;
              yrp(x):=diff(yr(x),x,1);
              yrpp(x):=diff(yr(x),x,2);

              sol:solve([yr(m)=t/2, yrp(m)=0],[d2,d3]);
              s2:rhs(subst(sol[1][1],d2,yrpp(m)));
              s3:ratsimp(rhs(subst(sol[1][2],d3,s2)));

              yf(x):= a0 * sqrt(x) + a1 * x + a2 * x^2 + a3 * x^3;
              yfp(x):=diff(yf(x),x,1);
              yfpp(x):=diff(yf(x),x,2);
              solve([yf(m)=t/2, yfp(m)=0, yfpp(m)=K],[a3,a2,a1]);
              solve([yf(m)=t/2, yfp(m)=0],[a2,a1]);
              solve([yf(m)=t/2],[a1]);
              */

              d3 = ( tocref + d1 * mt - d1 - 2.0 * d0 ) / ( xmtcu - 3.0 * xmtsq + 3.0 * mt - 1.0 );
              d2 = ( 3.0 * tocref + 4.0 * d1 * mt - 4.0 * d1 - 6.0 * d0 ) / ( 2.0 * xmtsq - 4.0 * mt + 2.0 );

              a0 = sqrt( 2.0 * rle );

              data_type ypp;
              ypp = -( 3.0 * tocref + 2.0 * d1 * mt - 2.0 * d1 - 6.0 * d0 ) / ( xmtsq - 2.0 * mt + 1.0 );

              a3 = ( 4.0 * tocref + 4.0 * ypp * xmtsq - 3.0 * a0 * srxmt ) / ( 8.0 * xmtcu );
              a2 = -( srxmt * tocref + 4.0 * a3 * srxmt * xmtcu - a0 * mt ) / ( 2.0 * srxmt * xmtsq );
              a1 = ( tocref - 2.0 * a3 * xmtcu - 2.0 * a2 * xmtsq - 2.0 * a0 * srxmt ) / ( 2.0 * mt );

              a(0) = a0;
              a(1) = a1;
              a(2) = a2;
              a(3) = a3;

              d(0) = d0;
              d(1) = d1;
              d(2) = d2;
              d(3) = d3;
            }

            void calc_thickness(data_type &y, data_type &yp, data_type &ypp, const data_type &xi) const
            {
              // check to make sure given valid parametric value
              assert((xi>=0) && (xi<=1));

              const data_type zero(0), one(1), two(2), three(3), four(4), six(6), half(one/two), quarter(one/four);
              const data_type trat(this->thickness/static_cast<data_type>(0.20));

              // short circuit for no thickness
              if (this->thickness==0)
              {
                y=zero;
                yp=zero;
                ypp=zero;
                return;
              }

              if (xi==0)
              {
                y=zero;
                yp=one/std::numeric_limits<data_type>::epsilon();
                ypp=yp;
                return;
              }
              else if ((xi==1) && this->sharp_trailing_edge())  // This is clearly wrong.
              {
                y=zero;
                yp=trat*(a.sum()-half*a(0));
                ypp=trat*(-quarter*a(0)+two*a(2)+six*a(3));
                return;
              }

              if (xi<thickness_loc)
              {
                const data_type xi2(xi*xi), xi3(xi*xi2), sqrtxi(std::sqrt(xi));

                y=trat*(a(0)*sqrtxi+a(1)*xi+a(2)*xi2+a(3)*xi3);
                yp=trat*(half*a(0)/sqrtxi+a(1)+two*a(2)*xi+three*a(3)*xi2);
                ypp=trat*(-quarter*a(0)/sqrtxi/xi+two*a(2)+six*a(3)*xi);
              }
              else
              {
                const data_type omx( one - xi );
                const data_type omx2(omx*omx), omx3(omx*omx2);

                y=trat*( d(0)+d(1)*omx+d(2)*omx2+d(3)*omx3 );
                yp=trat*( -d(1) - d(2)*two*omx - d(3)*three*omx2 );
                ypp=trat*( d(2)*two + d(3)*six*omx );
              }

            }

          protected:
            data_type thickness_loc; // chord-wise location of maximum thickness [0,.9]
            data_type le_radius_indx; // Leading edge radius index

            coefficient_type a; // coefficients for thickness distribution
            coefficient_type d; // coefficients for thickness distribution
        };
      }
    }
  }
}
#endif
