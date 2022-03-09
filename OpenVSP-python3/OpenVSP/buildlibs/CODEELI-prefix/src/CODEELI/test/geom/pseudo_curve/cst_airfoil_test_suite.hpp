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

#ifndef cst_airfoil_curve_test_suite_hpp
#define cst_airfoil_curve_test_suite_hpp

#include <cmath>    // std::pow, std::exp

#include <typeinfo> // typeid
#include <string>   // std::string
#include <sstream>  // std::stringstream
#include <iomanip>  // std::setw
#include <limits>   // std::numeric_limits

#include "eli/constants/math.hpp"
#include "eli/mutil/fd/d1o2.hpp"
#include "eli/mutil/fd/d2o2.hpp"

#include "eli/geom/point/distance.hpp"

#include "eli/geom/curve/length.hpp"
#include "eli/geom/curve/curvature.hpp"

#include "eli/geom/curve/pseudo/cst_airfoil.hpp"

#include "octave_helpers.hpp"

template<typename data__>
class cst_airfoil_test_suite : public Test::Suite
{
  private:
    typedef eli::geom::curve::pseudo::cst_airfoil<data__> curve_type;
    typedef typename curve_type::point_type point_type;
    typedef typename curve_type::data_type data_type;
    typedef typename curve_type::index_type index_type;
    typedef typename curve_type::control_point_type control_point_type;
    typedef typename curve_type::tolerance_type tolerance_type;

    tolerance_type tol;

  protected:
    void AddTests(const float &)
    {
      // add the tests
      TEST_ADD(cst_airfoil_test_suite<float>::assignment_test);
      TEST_ADD(cst_airfoil_test_suite<float>::evaluation_test);
      TEST_ADD(cst_airfoil_test_suite<float>::derivative_test);
      TEST_ADD(cst_airfoil_test_suite<float>::promotion_test);
      TEST_ADD(cst_airfoil_test_suite<float>::demotion_test);
    }
    void AddTests(const double &)
    {
      // add the tests
      TEST_ADD(cst_airfoil_test_suite<double>::assignment_test);
      TEST_ADD(cst_airfoil_test_suite<double>::evaluation_test);
      TEST_ADD(cst_airfoil_test_suite<double>::derivative_test);
      TEST_ADD(cst_airfoil_test_suite<double>::promotion_test);
      TEST_ADD(cst_airfoil_test_suite<double>::demotion_test);
    }
    void AddTests(const long double &)
    {
      // add the tests
      TEST_ADD(cst_airfoil_test_suite<long double>::assignment_test);
      TEST_ADD(cst_airfoil_test_suite<long double>::evaluation_test);
      TEST_ADD(cst_airfoil_test_suite<long double>::derivative_test);
      TEST_ADD(cst_airfoil_test_suite<long double>::promotion_test);
      TEST_ADD(cst_airfoil_test_suite<long double>::demotion_test);
    }

  public:
    cst_airfoil_test_suite()
    {
      AddTests(data__());
    }
    ~cst_airfoil_test_suite()
    {
    }

  private:
    void assignment_test()
    {
      curve_type cst1, cst2;
      control_point_type cntrl_in[4], cntrl_out;

      // test default constructor then set control points
      cntrl_in[0] << 2;
      cntrl_in[1] << 1;
      cntrl_in[2] << static_cast<data_type>(3.5);
      cntrl_in[3] << 4;

      cst1.resize_upper(3);
      for (index_type i=0; i<=cst1.upper_degree(); ++i)
      {
        cst1.set_upper_control_point(cntrl_in[i], i);
      }
      cst1.resize_lower(3);
      for (index_type i=0; i<=cst1.lower_degree(); ++i)
      {
        cst1.set_lower_control_point(-cntrl_in[i], i);
      }

      // test order
      TEST_ASSERT(cst1.upper_degree()==3);
      TEST_ASSERT(cst1.lower_degree()==3);

      // test control points
      for (index_type i=0; i<=cst1.upper_degree(); ++i)
      {
        TEST_ASSERT(tol.approximately_equal(cst1.get_upper_control_point(i), cntrl_in[i]));
      }
      for (index_type i=0; i<=cst1.lower_degree(); ++i)
      {
        TEST_ASSERT(tol.approximately_equal(cst1.get_lower_control_point(i), -cntrl_in[i]));
      }

      // test copy ctr
      curve_type cstc2(cst1);
      TEST_ASSERT(cstc2==cst1);

      // test assignment operator
      cst2=cst1;
      TEST_ASSERT(cst2==cst1);
    }

    void evaluation_test()
    {
      typedef eli::geom::curve::pseudo::explicit_bezier<data_type> explicit_bezier_curve_type;

      explicit_bezier_curve_type ebcu(7), ebcl(7);
      curve_type cst(7);
      control_point_type cp[8];
      data_type dte(0.01), t[6];
      point_type pt_out, pt_ref;
      index_type i;

      // set the control points
      cp[0] << static_cast<data_type>(0.170987592880629);
      cp[1] << static_cast<data_type>(0.157286894410384);
      cp[2] << static_cast<data_type>(0.162311658384540);
      cp[3] << static_cast<data_type>(0.143623187913493);
      cp[4] << static_cast<data_type>(0.149218456400780);
      cp[5] << static_cast<data_type>(0.137218405082418);
      cp[6] << static_cast<data_type>(0.140720628655908);
      cp[7] << static_cast<data_type>(0.141104769355436);
      for (i=0; i<=cst.upper_degree(); ++i)
      {
        ebcu.set_control_point(cp[i], i);
        cst.set_upper_control_point(cp[i], i);
        ebcl.set_control_point(-cp[i], i);
        cst.set_lower_control_point(-cp[i], i);
      }

      // set the trailing edge thickness of CST airfoil
      cst.set_trailing_edge_thickness(dte);

      // set the parameters to evaluate the tests
      t[0] = static_cast<data_type>(0);
      t[1] = static_cast<data_type>(0.1);
      t[2] = static_cast<data_type>(0.27);
      t[3] = static_cast<data_type>(0.5);
      t[4] = static_cast<data_type>(0.73);
      t[5] = static_cast<data_type>(1);

      // evaluate the points on lower surface
      i=1;
      pt_out = cst.f(-t[i]);
      pt_ref = ebcu.f(t[i]);
      pt_ref(1) = -(std::sqrt(t[i])*(1-t[i])*pt_ref(1)+t[i]*dte/2);
      TEST_ASSERT(tol.approximately_equal(pt_out, pt_ref));
      i=2;
      pt_out = cst.f(-t[i]);
      pt_ref = ebcu.f(t[i]);
      pt_ref(1) = -(std::sqrt(t[i])*(1-t[i])*pt_ref(1)+t[i]*dte/2);
      TEST_ASSERT(tol.approximately_equal(pt_out, pt_ref));
      i=3;
      pt_out = cst.f(-t[i]);
      pt_ref = ebcu.f(t[i]);
      pt_ref(1) = -(std::sqrt(t[i])*(1-t[i])*pt_ref(1)+t[i]*dte/2);
      TEST_ASSERT(tol.approximately_equal(pt_out, pt_ref));
      i=4;
      pt_out = cst.f(-t[i]);
      pt_ref = ebcu.f(t[i]);
      pt_ref(1) = -(std::sqrt(t[i])*(1-t[i])*pt_ref(1)+t[i]*dte/2);
      TEST_ASSERT(tol.approximately_equal(pt_out, pt_ref));
      i=5;
      pt_out = cst.f(-t[i]);
      pt_ref = ebcu.f(t[i]);
      pt_ref(1) = -(std::sqrt(t[i])*(1-t[i])*pt_ref(1)+t[i]*dte/2);
      TEST_ASSERT(tol.approximately_equal(pt_out, pt_ref));

      // evaluate the points on upper surface
      i=0;
      pt_out = cst.f(t[i]);
      pt_ref = ebcu.f(t[i]);
      pt_ref(1) = std::sqrt(t[i])*(1-t[i])*pt_ref(1)+t[i]*dte/2;
      TEST_ASSERT(tol.approximately_equal(pt_out, pt_ref));
      i=1;
      pt_out = cst.f(t[i]);
      pt_ref = ebcu.f(t[i]);
      pt_ref(1) = std::sqrt(t[i])*(1-t[i])*pt_ref(1)+t[i]*dte/2;
      TEST_ASSERT(tol.approximately_equal(pt_out, pt_ref));
      i=2;
      pt_out = cst.f(t[i]);
      pt_ref = ebcu.f(t[i]);
      pt_ref(1) = std::sqrt(t[i])*(1-t[i])*pt_ref(1)+t[i]*dte/2;
      TEST_ASSERT(tol.approximately_equal(pt_out, pt_ref));
      i=3;
      pt_out = cst.f(t[i]);
      pt_ref = ebcu.f(t[i]);
      pt_ref(1) = std::sqrt(t[i])*(1-t[i])*pt_ref(1)+t[i]*dte/2;
      TEST_ASSERT(tol.approximately_equal(pt_out, pt_ref));
      i=4;
      pt_out = cst.f(t[i]);
      pt_ref = ebcu.f(t[i]);
      pt_ref(1) = std::sqrt(t[i])*(1-t[i])*pt_ref(1)+t[i]*dte/2;
      TEST_ASSERT(tol.approximately_equal(pt_out, pt_ref));
      i=5;
      pt_out = cst.f(t[i]);
      pt_ref = ebcu.f(t[i]);
      pt_ref(1) = std::sqrt(t[i])*(1-t[i])*pt_ref(1)+t[i]*dte/2;
      TEST_ASSERT(tol.approximately_equal(pt_out, pt_ref));
    }

    void derivative_test()
    {
      curve_type cst(7);
      control_point_type cp[8];
      data_type dte(0.01), t[6];
      point_type pt, xp, xp_ref, xpp, xpp_ref;
      index_type i;

      // set the control points
      cp[0] << static_cast<data_type>(0.170987592880629);
      cp[1] << static_cast<data_type>(0.157286894410384);
      cp[2] << static_cast<data_type>(0.162311658384540);
      cp[3] << static_cast<data_type>(0.143623187913493);
      cp[4] << static_cast<data_type>(0.149218456400780);
      cp[5] << static_cast<data_type>(0.137218405082418);
      cp[6] << static_cast<data_type>(0.140720628655908);
      cp[7] << static_cast<data_type>(0.141104769355436);
      for (i=0; i<=cst.upper_degree(); ++i)
      {
        cst.set_upper_control_point(cp[i], i);
        cst.set_lower_control_point(-cp[i], i);
      }

      // set the trailing edge thickness of CST airfoil
      cst.set_trailing_edge_thickness(dte);

      // set the parameters to evaluate the tests
      t[0] = static_cast<data_type>(0.1);
      t[1] = static_cast<data_type>(0.24);
      t[2] = static_cast<data_type>(0.42);
      t[3] = static_cast<data_type>(0.5);
      t[4] = static_cast<data_type>(0.73);
      t[5] = static_cast<data_type>(0.95);

      data_type x[3], y[3], dt(static_cast<data_type>(1e2)*std::sqrt(std::numeric_limits<data_type>::epsilon()));
      eli::mutil::fd::d1o2<data_type> d1_calc;
      eli::mutil::fd::d2o2<data_type> d2_calc;

      // evaluate points on the lower surface
      for (i=0; i<6; ++i)
      {
        pt=cst.f(-t[i]-dt); x[0]=pt(0); y[0]=pt(1);
        pt=cst.f(-t[i]);    x[1]=pt(0); y[1]=pt(1);
        pt=cst.f(-t[i]+dt); x[2]=pt(0); y[2]=pt(1);
        d1_calc.evaluate(xp_ref(0), x, dt);
        d1_calc.evaluate(xp_ref(1), y, dt);
        d2_calc.evaluate(xpp_ref(0), x, dt);
        d2_calc.evaluate(xpp_ref(1), y, dt);
        xp=cst.fp(-t[i]);
        xpp=cst.fpp(-t[i]);
        if (typeid(data_type)==typeid(float))
        {
          TEST_ASSERT((xp-xp_ref).norm()<6e-3);
          if (i==0)
          {
            TEST_ASSERT((xpp-xpp_ref).norm()<7e-2);
          }
          else if (i==1)
          {
            TEST_ASSERT((xpp-xpp_ref).norm()<4e-3);
          }
          else
          {
            TEST_ASSERT((xpp-xpp_ref).norm()<3e-3);
          }
        }
        else
        {
          TEST_ASSERT(tol.approximately_equal(xp, xp_ref));
          TEST_ASSERT((xpp-xpp_ref).norm()<8e-5);
        }
      }

      // evaluate points on the upper surface
      for (i=0; i<6; ++i)
      {
        pt=cst.f(t[i]-dt); x[0]=pt(0); y[0]=pt(1);
        pt=cst.f(t[i]);    x[1]=pt(0); y[1]=pt(1);
        pt=cst.f(t[i]+dt); x[2]=pt(0); y[2]=pt(1);
        d1_calc.evaluate(xp_ref(0), x, dt);
        d1_calc.evaluate(xp_ref(1), y, dt);
        d2_calc.evaluate(xpp_ref(0), x, dt);
        d2_calc.evaluate(xpp_ref(1), y, dt);
        xp=cst.fp(t[i]);
        xpp=cst.fpp(t[i]);
        if (typeid(data_type)==typeid(float))
        {
          TEST_ASSERT((xp-xp_ref).norm()<6e-3);
          if (i==0)
          {
            TEST_ASSERT((xpp-xpp_ref).norm()<7e-2);
          }
          else if (i==1)
          {
            TEST_ASSERT((xpp-xpp_ref).norm()<4e-3);
          }
          else
          {
            TEST_ASSERT((xpp-xpp_ref).norm()<3e-3);
          }
        }
        else
        {
          TEST_ASSERT(tol.approximately_equal(xp, xp_ref));
          TEST_ASSERT((xpp-xpp_ref).norm()<8e-5);
        }
      }
    }

    void promotion_test()
    {
      typedef eli::geom::curve::pseudo::explicit_bezier<data__> reference_curve_type;

      curve_type cst;
      control_point_type cntrl_in[5], cntrl_out;
      reference_curve_type refu, refl;

      // set control points
      cntrl_in[0] << 2;
      cntrl_in[1] << static_cast<data_type>(1.5);
      cntrl_in[2] << 0;
      cntrl_in[3] << 1;
      cntrl_in[4] << static_cast<data_type>(0.5);

      cst.resize_upper(4);
      cst.resize_lower(4);
      refu.resize(4);
      refl.resize(4);
      for (index_type i=0; i<=cst.upper_degree(); ++i)
      {
        cst.set_upper_control_point(cntrl_in[i], i);
        refu.set_control_point(cntrl_in[i], i);
        cst.set_lower_control_point(-cntrl_in[i], i);
        refl.set_control_point(-cntrl_in[i], i);
      }

      // test promote lower surface
      cst.lower_degree_promote();
      refl.degree_promote();
      TEST_ASSERT(cst.lower_degree()==refl.degree());
      for (index_type i=0; i<cst.lower_degree(); ++i)
      {
        TEST_ASSERT(tol.approximately_equal(cst.get_lower_control_point(i), refl.get_control_point(i)));
      }

      // test promote upper surface
      cst.upper_degree_promote();
      refu.degree_promote();
      TEST_ASSERT(cst.upper_degree()==refu.degree());
      for (index_type i=0; i<cst.upper_degree(); ++i)
      {
        TEST_ASSERT(tol.approximately_equal(cst.get_upper_control_point(i), refu.get_control_point(i)));
      }
    }

    void demotion_test()
    {
      // C0 constraint
      {
        typedef eli::geom::curve::pseudo::explicit_bezier<data__> reference_curve_type;

        curve_type cst, cst_orig;
        control_point_type cntrl_in[5], cntrl_out;
        reference_curve_type refu, refl;
        point_type pt, pt_ref;

        // set control points
        cntrl_in[0] << 2;
        cntrl_in[1] << static_cast<data_type>(1.5);
        cntrl_in[2] << 0;
        cntrl_in[3] << 1;
        cntrl_in[4] << static_cast<data_type>(0.5);

        cst.resize_upper(4);
        cst.resize_lower(4);
        refu.resize(4);
        refl.resize(4);
        for (index_type i=0; i<=cst.upper_degree(); ++i)
        {
          cst.set_upper_control_point(cntrl_in[i], i);
          cst.set_lower_control_point(cntrl_in[i], i);
          refu.set_control_point(cntrl_in[i], i);
          refl.set_control_point(cntrl_in[i], i);
        }
        cst_orig=cst;

        // demote the lower surface
        cst.lower_degree_demote(eli::geom::general::C0);
        refl.degree_demote(eli::geom::general::NOT_CONNECTED);
        TEST_ASSERT(cst.lower_degree()==refl.degree());
        for (index_type i=0; i<cst.lower_degree(); ++i)
        {
          TEST_ASSERT(tol.approximately_equal(cst.get_lower_control_point(i), refl.get_control_point(i)));
        }
        TEST_ASSERT(tol.approximately_equal(cst.f(-1), cst_orig.f(-1)));
        TEST_ASSERT(tol.approximately_equal(cst.f(0), cst_orig.f(0)));

        // demote the upper surface
        cst.upper_degree_demote(eli::geom::general::C0);
        refu.degree_demote(eli::geom::general::NOT_CONNECTED);
        TEST_ASSERT(cst.upper_degree()==refu.degree());
        for (index_type i=0; i<cst.upper_degree(); ++i)
        {
          TEST_ASSERT(tol.approximately_equal(cst.get_upper_control_point(i), refu.get_control_point(i)));
        }
        TEST_ASSERT(tol.approximately_equal(cst.f(0), cst_orig.f(0)));
        TEST_ASSERT(tol.approximately_equal(cst.f(1), cst_orig.f(1)));
      }

      // C1 constraint
      {
        typedef eli::geom::curve::pseudo::explicit_bezier<data__> reference_curve_type;

        curve_type cst, cst_orig;
        control_point_type cntrl_in[5], cntrl_out;
        reference_curve_type refu, refl;

        // set control points
        cntrl_in[0] << 2;
        cntrl_in[1] << static_cast<data_type>(1.5);
        cntrl_in[2] << 0;
        cntrl_in[3] << 1;
        cntrl_in[4] << static_cast<data_type>(0.5);

        cst.resize_upper(4);
        cst.resize_lower(4);
        refu.resize(4);
        refl.resize(4);
        for (index_type i=0; i<=cst.upper_degree(); ++i)
        {
          cst.set_upper_control_point(cntrl_in[i], i);
          cst.set_lower_control_point(cntrl_in[i], i);
          refu.set_control_point(cntrl_in[i], i);
          refl.set_control_point(cntrl_in[i], i);
        }
        cst_orig=cst;

        // demote the lower surface
        cst.lower_degree_demote(eli::geom::general::C1);
        refl.degree_demote(eli::geom::general::C0);
        TEST_ASSERT(cst.lower_degree()==refl.degree());
        for (index_type i=0; i<cst.lower_degree(); ++i)
        {
          TEST_ASSERT(tol.approximately_equal(cst.get_lower_control_point(i), refl.get_control_point(i)));
        }
        TEST_ASSERT(tol.approximately_equal(cst.f(-1), cst_orig.f(-1)));
        TEST_ASSERT(tol.approximately_equal(cst.fp(-1), cst_orig.fp(-1)));
        TEST_ASSERT(tol.approximately_equal(cst.f(0), cst_orig.f(0)));

        // demote the upper surface
        cst.upper_degree_demote(eli::geom::general::C1);
        refu.degree_demote(eli::geom::general::C0);
        TEST_ASSERT(cst.upper_degree()==refu.degree());
        for (index_type i=0; i<cst.upper_degree(); ++i)
        {
          TEST_ASSERT(tol.approximately_equal(cst.get_upper_control_point(i), refu.get_control_point(i)));
        }
        TEST_ASSERT(tol.approximately_equal(cst.f(0), cst_orig.f(0)));
        TEST_ASSERT(tol.approximately_equal(cst.f(1), cst_orig.f(1)));
        TEST_ASSERT(tol.approximately_equal(cst.fp(1), cst_orig.fp(1)));
      }

      // C2 constraint
      {
        typedef eli::geom::curve::pseudo::explicit_bezier<data__> reference_curve_type;

        curve_type cst, cst_orig;
        control_point_type cntrl_in[5], cntrl_out;
        reference_curve_type refu, refl;

        // set control points
        cntrl_in[0] << 2;
        cntrl_in[1] << static_cast<data_type>(1.5);
        cntrl_in[2] << 0;
        cntrl_in[3] << 1;
        cntrl_in[4] << static_cast<data_type>(0.5);

        cst.resize_upper(4);
        cst.resize_lower(4);
        refu.resize(4);
        refl.resize(4);
        for (index_type i=0; i<=cst.upper_degree(); ++i)
        {
          cst.set_upper_control_point(cntrl_in[i], i);
          cst.set_lower_control_point(cntrl_in[i], i);
          refu.set_control_point(cntrl_in[i], i);
          refl.set_control_point(cntrl_in[i], i);
        }
        cst_orig=cst;

        // demote the lower surface
        cst.lower_degree_demote(eli::geom::general::C2);
        refl.degree_demote(eli::geom::general::C1);
        TEST_ASSERT(cst.lower_degree()==refl.degree());
        for (index_type i=0; i<cst.lower_degree(); ++i)
        {
          TEST_ASSERT(tol.approximately_equal(cst.get_lower_control_point(i), refl.get_control_point(i)));
        }
        TEST_ASSERT(tol.approximately_equal(cst.f(-1), cst_orig.f(-1)));
        TEST_ASSERT(tol.approximately_equal(cst.fp(-1), cst_orig.fp(-1)));
        TEST_ASSERT(tol.approximately_equal(cst.fpp(-1), cst_orig.fpp(-1)));
        TEST_ASSERT(tol.approximately_equal(cst.f(0), cst_orig.f(0)));

        // demote the upper surface
        cst.upper_degree_demote(eli::geom::general::C2);
        refu.degree_demote(eli::geom::general::C1);
        TEST_ASSERT(cst.upper_degree()==refu.degree());
        for (index_type i=0; i<cst.upper_degree(); ++i)
        {
          TEST_ASSERT(tol.approximately_equal(cst.get_upper_control_point(i), refu.get_control_point(i)));
        }
        TEST_ASSERT(tol.approximately_equal(cst.f(0), cst_orig.f(0)));
        TEST_ASSERT(tol.approximately_equal(cst.f(1), cst_orig.f(1)));
        TEST_ASSERT(tol.approximately_equal(cst.fp(1), cst_orig.fp(1)));
        TEST_ASSERT(tol.approximately_equal(cst.fpp(1), cst_orig.fpp(1)));
      }
    }
};
#endif

