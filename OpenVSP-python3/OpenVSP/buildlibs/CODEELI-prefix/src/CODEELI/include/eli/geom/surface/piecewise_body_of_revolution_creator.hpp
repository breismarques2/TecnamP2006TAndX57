/*********************************************************************************
* Copyright (c) 2013 David D. Marshall <ddmarsha@calpoly.edu>
*
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
*    David D. Marshall - initial code and implementation
********************************************************************************/

#ifndef eli_geom_surface_piecewise_body_of_revolution_creator_hpp
#define eli_geom_surface_piecewise_body_of_revolution_creator_hpp

#include <list>
#include <iterator>

#include "eli/code_eli.hpp"

#include "eli/util/tolerance.hpp"

#include "eli/geom/curve/piecewise.hpp"
#include "eli/geom/curve/piecewise_creator.hpp"

#include "eli/geom/surface/piecewise.hpp"
#include "eli/geom/surface/bezier.hpp"

namespace eli
{
  namespace geom
  {
    namespace surface
    {
      template<typename data__, unsigned short dim__, typename tol__>
      bool create_body_of_revolution(piecewise<bezier, data__, dim__, tol__> &ps,
                                     const eli::geom::curve::piecewise<eli::geom::curve::bezier, data__, dim__, tol__> &pc,
                                     int axis, bool outward_normal, bool match_uparm = false)
      {
        typedef piecewise<bezier, data__, dim__, tol__> piecewise_surface_type;
        typedef eli::geom::curve::piecewise<eli::geom::curve::bezier, data__, dim__, tol__> piecewise_curve_type;
        typedef eli::geom::curve::piecewise_circle_creator<data__, dim__, tol__> circle_creator_type;
        typedef typename piecewise_curve_type::curve_type curve_type;
        typedef typename piecewise_surface_type::surface_type surface_type;
        typedef typename curve_type::point_type point_type;
        typedef typename curve_type::data_type data_type;
        typedef typename curve_type::index_type index_type;

        curve_type c, arc;
        surface_type s[4];
        piecewise_curve_type pc_circle;
        point_type origin, normal, start;
        data_type du, dv;
        index_type i, j, pp, qq, nu=pc.number_segments(), nv=4, udeg, vdeg;

        // resize the surface
        if ( match_uparm )
        {
          std::vector<data_type> umap, du;
          pc.get_pmap( umap );

          for ( i = 0; i < nu; i++ )
          {
            du.push_back( umap[ i + 1 ] - umap[ i ] );
          }

          ps.init_uv( du.begin(), du.end(), nv, 1, umap[0] );
        }
        else
        {
          ps.init_uv(nu, nv);
        }

        // set the axis of rotation
        switch(axis)
        {
          case(0):
          {
            normal << 1, 0, 0;
            break;
          }
          case(1):
          {
            normal << 0, 1, 0;
            break;
          }
          case(2):
          {
            normal << 0, 0, 1;
            break;
          }
          default:
          {
            assert(false);
            return false;
          }
        }
        if (outward_normal)
        {
          normal*=-1;
        }

        // cycle through each curve segment
        circle_creator_type circle_creator;
        for (pp=0; pp<nu; ++pp)
        {
          // resize the surface patch
          vdeg=3;
          pc.get(c, du, pp);
          udeg = c.degree();

          s[0].resize(udeg, vdeg);
          s[1].resize(udeg, vdeg);
          s[2].resize(udeg, vdeg);
          s[3].resize(udeg, vdeg);

          // cycle through each control point in current curve and create patch control points
          for (i=0; i<=udeg; ++i)
          {
            // set up the vectors for this circle
            start=c.get_control_point(i);
            origin=normal.dot(start)*normal;

            // get the circle
            circle_creator.set(start, origin, normal);
            if (!circle_creator.create(pc_circle))
            {
              assert(false);
              return false;
            }

            // for each segment of circle set the control points
            for (qq=0; qq<4; ++qq)
            {
              pc_circle.get(arc, dv, qq);
              for (j=0; j<4; ++j)
              {
                s[qq].set_control_point(arc.get_control_point(j), i, j);
              }
            }
          }

          // set the surface patches
          for (qq=0; qq<4; ++qq)
          {
            ps.set(s[qq], pp, qq);
          }
        }

        return true;
      }
    }
  }
}
#endif
