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

#ifndef minimum_distance_curve_test_suite_hpp
#define minimum_distance_curve_test_suite_hpp

#include <cmath>    // cos(), sin()

#include <typeinfo> // typeid

#include "eli/geom/curve/bezier.hpp"
#include "eli/geom/intersect/minimum_distance_curve.hpp"
#include "eli/geom/curve/piecewise.hpp"

template<typename data__>
class minimum_distance_curve_test_suite : public Test::Suite
{
  private:
    typedef data__ data_type;

    typedef eli::geom::curve::bezier<data_type, 2> curve_type2;
    typedef typename curve_type2::point_type point_type2;
    typedef typename curve_type2::index_type index_type2;

    typedef eli::geom::curve::piecewise<eli::geom::curve::bezier, data__, 3> piecewise_curve_type3;
    typedef typename piecewise_curve_type3::curve_type curve_type3;
    typedef typename curve_type3::point_type point_type3;
    typedef typename curve_type3::index_type index_type3;

    typedef typename curve_type2::tolerance_type tolerance_type;

    typedef eli::geom::curve::bezier<data_type, 1> curve_type1;
    typedef typename curve_type1::point_type point_type1;
    typedef typename curve_type1::index_type index_type1;

    tolerance_type tol;

  protected:
    void AddTests(const float &)
    {
      // add the tests
      TEST_ADD(minimum_distance_curve_test_suite<float>::point_smooth_2d_test);
      TEST_ADD(minimum_distance_curve_test_suite<float>::point_closed_2d_test);
      TEST_ADD(minimum_distance_curve_test_suite<float>::point_smooth_3d_test);
      TEST_ADD(minimum_distance_curve_test_suite<float>::point_closed_3d_test);
      TEST_ADD(minimum_distance_curve_test_suite<float>::point_piecewise_01_smooth_3d_test);
      TEST_ADD(minimum_distance_curve_test_suite<float>::point_piecewise_trange_smooth_3d_test);
      TEST_ADD(minimum_distance_curve_test_suite<float>::dist_surf_test);
    }
    void AddTests(const double &)
    {
      // add the tests
      TEST_ADD(minimum_distance_curve_test_suite<double>::point_smooth_2d_test);
      TEST_ADD(minimum_distance_curve_test_suite<double>::point_closed_2d_test);
      TEST_ADD(minimum_distance_curve_test_suite<double>::point_smooth_3d_test);
      TEST_ADD(minimum_distance_curve_test_suite<double>::point_closed_3d_test);
      TEST_ADD(minimum_distance_curve_test_suite<double>::point_piecewise_01_smooth_3d_test);
      TEST_ADD(minimum_distance_curve_test_suite<double>::point_piecewise_trange_smooth_3d_test);
      TEST_ADD(minimum_distance_curve_test_suite<double>::dist_surf_test);
    }
    void AddTests(const long double &)
    {
      // add the tests
      TEST_ADD(minimum_distance_curve_test_suite<long double>::point_smooth_2d_test);
      TEST_ADD(minimum_distance_curve_test_suite<long double>::point_closed_2d_test);
      TEST_ADD(minimum_distance_curve_test_suite<long double>::point_smooth_3d_test);
      TEST_ADD(minimum_distance_curve_test_suite<long double>::point_closed_3d_test);
      TEST_ADD(minimum_distance_curve_test_suite<long double>::point_piecewise_01_smooth_3d_test);
      TEST_ADD(minimum_distance_curve_test_suite<long double>::point_piecewise_trange_smooth_3d_test);
      TEST_ADD(minimum_distance_curve_test_suite<long double>::dist_surf_test);
    }

  public:
    minimum_distance_curve_test_suite()
    {
      AddTests(data__());
    }
    ~minimum_distance_curve_test_suite()
    {
    }

  private:
    void octave_print(int figno, const curve_type1 &c) const
    {
      size_t i, n(c.degree());

      std::vector<data__> t(101);
      for (i=0; i<t.size(); ++i)
        t[i]=static_cast<data__>(i)/(t.size()-1);

      std::cout << "t=[" << t[0];
      for (i=1; i<t.size(); ++i)
        std::cout << ", " << t[i];
      std::cout << "];" << std::endl;

      std::cout << "xint=[" << c.f(t[0])(0);
      for (i=1; i<t.size(); ++i)
        std::cout << ", " << c.f(t[i])(0);
      std::cout << "];" << std::endl;

      std::vector<data__> tcp(n+1);
      for (i=0; i<=n; ++i)
        tcp[i]=static_cast<data__>(i)/(tcp.size()-1);

      std::cout << "tcp=[" << t[0];
      for (i=1; i<tcp.size(); ++i)
        std::cout << ", " << tcp[i];
      std::cout << "];" << std::endl;

      std::cout << "xcp=[" << c.get_control_point(0)(0);
      for (i=1; i<=n; ++i)
        std::cout << ", " << c.get_control_point(i)(0);
      std::cout << "];" << std::endl;

      std::cout << "figure(" << figno << ");" << std::endl;
      std::cout << "setenv('GNUTERM', 'x11');" << std::endl;
      std::cout << "plot( t, xint, 'k-', tcp, xcp, 'bx' );" << std::endl;
    }

    void octave_print(int figno, const std::vector<point_type2> &pts, const curve_type2 &c) const
    {
      size_t i;

      std::cout << "figure(" << figno << ");" << std::endl;
      std::cout << "xpts=[" << pts[0].x();
      for (i=1; i<pts.size(); ++i)
        std::cout << ", " << pts[i].x();
      std::cout << "];" << std::endl;
      std::cout << "ypts=[" << pts[0].y();
      for (i=1; i<pts.size(); ++i)
        std::cout << ", " << pts[i].y();
      std::cout << "];" << std::endl;

      std::vector<data__> t(101);
      for (i=0; i<t.size(); ++i)
        t[i]=static_cast<data__>(i)/(t.size()-1);

      std::cout << "xint=[" << c.f(t[0])(0);
      for (i=1; i<t.size(); ++i)
        std::cout << ", " << c.f(t[i])(0);
      std::cout << "];" << std::endl;
      std::cout << "yint=[" << c.f(t[0])(1);
      for (i=1; i<t.size(); ++i)
        std::cout << ", " << c.f(t[i])(1);
      std::cout << "];" << std::endl;

      std::cout << "setenv('GNUTERM', 'x11');" << std::endl;
      std::cout << "plot(xpts, ypts, 'bo', xint, yint, 'k-');" << std::endl;

      std::cout << "figure(" << figno+1 << ");" << std::endl;
      std::cout << "t=[" << t[0];
      for (i=1; i<t.size(); ++i)
        std::cout << ", " << t[i];
      std::cout << "];" << std::endl;
      std::cout << "g=[" << (c.f(t[0])-pts[0]).dot(c.fp(t[0]));
      for (i=1; i<t.size(); ++i)
        std::cout << ", " << (c.f(t[i])-pts[0]).dot(c.fp(t[i]));
      std::cout << "];" << std::endl;

      std::cout << "plot([0,1], [0, 0], 'k-', t, g, 'k-');" << std::endl;

      std::cout << "figure(" << figno+1 << ");" << std::endl;

      std::cout << "d=[" << (c.f(t[0])-pts[0]).norm();
      for (i=1; i<t.size(); ++i)
        std::cout << ", " << (c.f(t[i])-pts[0]).norm();
      std::cout << "];" << std::endl;

      std::cout << "plot( t, d, 'k-');" << std::endl;



    }

    void octave_print(int figno, const std::vector<point_type3> &pts, const curve_type3 &c) const
    {
      size_t i;

      std::cout << std::endl;
      std::cout << "figure(" << figno << ");" << std::endl;
      std::cout << "xpts=[" << pts[0].x();
      for (i=1; i<pts.size(); ++i)
        std::cout << ", " << pts[i].x();
      std::cout << "];" << std::endl;
      std::cout << "ypts=[" << pts[0].y();
      for (i=1; i<pts.size(); ++i)
        std::cout << ", " << pts[i].y();
      std::cout << "];" << std::endl;
      std::cout << "zpts=[" << pts[0].z();
      for (i=1; i<pts.size(); ++i)
        std::cout << ", " << pts[i].z();
      std::cout << "];" << std::endl;

      std::vector<data__> t(101);
      for (i=0; i<t.size(); ++i)
        t[i]=static_cast<data__>(i)/(t.size()-1);

      std::cout << "xint=[" << c.f(t[0]).x();
      for (i=1; i<t.size(); ++i)
        std::cout << ", " << c.f(t[i]).x();
      std::cout << "];" << std::endl;
      std::cout << "yint=[" << c.f(t[0]).y();
      for (i=1; i<t.size(); ++i)
        std::cout << ", " << c.f(t[i]).y();
      std::cout << "];" << std::endl;
      std::cout << "zint=[" << c.f(t[0]).z();
      for (i=1; i<t.size(); ++i)
        std::cout << ", " << c.f(t[i]).z();
      std::cout << "];" << std::endl;

      std::cout << "setenv('GNUTERM', 'x11');" << std::endl;
      std::cout << "plot3(xpts, ypts, zpts, 'bo', xint, yint, zint, 'k-');" << std::endl;
      std::cout << "axis equal" << std::endl;

      std::cout << "figure(" << figno+1 << ");" << std::endl;
      std::cout << "t=[" << t[0];
      for (i=1; i<t.size(); ++i)
        std::cout << ", " << t[i];
      std::cout << "];" << std::endl;
      std::cout << "g=[" << (c.f(t[0])-pts[0]).dot(c.fp(t[0]));
      for (i=1; i<t.size(); ++i)
        std::cout << ", " << (c.f(t[i])-pts[0]).dot(c.fp(t[i]));
      std::cout << "];" << std::endl;

      std::cout << "plot([0,1], [0, 0], 'k-', t, g, 'k-');" << std::endl << std::endl;
    }

    void point_smooth_2d_test()
    {
      point_type2 cntrl_in[4];

      // set control points
      cntrl_in[0] <<-1, 2;
      cntrl_in[1] << 0, 1;
      cntrl_in[2] << 3, 0;
      cntrl_in[3] << 4, 1;

      curve_type2 c(3);
      point_type2 pt, norm;
      data_type  dist, t, dist_ref, t_ref;

      // set control points
      for (index_type2 i=0; i<4; ++i)
      {
        c.set_control_point(cntrl_in[i], i);
      }

      // test point on curve
      dist_ref=0;
      t_ref=0.25;
      norm << -c.fp(t_ref).y(), c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point very near curve
      dist_ref=static_cast<data_type>(0.01);
      t_ref=0.25;
      norm << -c.fp(t_ref).y(), c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=0.25;
      norm << -c.fp(t_ref).y(), c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point far from curve
      dist_ref=static_cast<data_type>(1.5);
      t_ref=0.25;
      norm << -c.fp(t_ref).y(), c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point on curve
      dist_ref=0;
      t_ref=static_cast<data_type>(0.6);
      norm << -c.fp(t_ref).y(), c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.65);
      norm << -c.fp(t_ref).y(), c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near end of curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.01);
      norm << -c.fp(t_ref).y(), c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point very near end of curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.001);
      norm << -c.fp(t_ref).y(), c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point very near end of curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.999);
      norm << -c.fp(t_ref).y(), c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point beyond start of curve
      t_ref=static_cast<data_type>(0);
      pt << -2, 2;
      dist_ref=(cntrl_in[0]-pt).norm();
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point beyond end of curve
      t_ref=static_cast<data_type>(1);
      pt << 5, 2;
      dist_ref=(cntrl_in[3]-pt).norm();
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));
    }

    void point_closed_2d_test()
    {
      point_type2 cntrl_in[13];

      // set control points
      cntrl_in[0]  <<   1, 0;
      cntrl_in[1]  <<   1, 0.5;
      cntrl_in[2]  << 0.5, 1;
      cntrl_in[3]  <<   0, 1;
      cntrl_in[4]  <<-0.5, 1;
      cntrl_in[5]  <<  -1, 0.5;
      cntrl_in[6]  <<  -1, 0;
      cntrl_in[7]  <<  -1,-0.5;
      cntrl_in[8]  <<-0.5,-1;
      cntrl_in[9]  <<   0,-1;
      cntrl_in[10] << 0.5,-1;
      cntrl_in[11] <<   1,-0.5;
      cntrl_in[12] <<   1,0;

      curve_type2 c(12);
      point_type2 pt, norm;
      data_type  dist, t, dist_ref, t_ref;

      // set control points
      for (index_type2 i=0; i<13; ++i)
      {
        c.set_control_point(cntrl_in[i], i);
      }

      // test point on curve
      dist_ref=0;
      t_ref=0.25;
      norm << -c.fp(t_ref).y(), c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=0.25;
      norm << -c.fp(t_ref).y(), c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near center
      dist_ref=static_cast<data_type>(0.77);
      t_ref=0.25;
      norm << -c.fp(t_ref).y(), c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      curve_type1 ans;

      ans = c.mindistcurve( pt );

//      if (typeid(data_type)==typeid(double))
//      {
//        octave_print( 1, ans );
//
//        std::cout << "% c_f(t_ref)=" << c.f(t_ref) << "\tpt=" << pt << std::endl;
//        std::cout << "% dist=" << dist << "\tdist_ref=" << dist_ref << "\tt=" << t << "\tt_ref=" << t_ref << std::endl;
//        std::cout << "% dist to end=" << (cntrl_in[0]-pt).norm() << std::endl;
//        std::vector<point_type2> vec(3);
//        vec[0]=pt;
//        vec[1]=c.f(t);
//        vec[2]=c.f(t_ref);
//        octave_print(2, vec, c);
//        exit(0);
//
//      }

      // test point near and outside curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.7);
      norm << c.fp(t_ref).y(), -c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point far and outside curve
      dist_ref=3;
      t_ref=static_cast<data_type>(0.7);
      norm << c.fp(t_ref).y(), -c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near end of curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.999);
      norm << -c.fp(t_ref).y(), c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near end of and outside curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.999);
      norm << c.fp(t_ref).y(), -c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near start of curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.001);
      norm << -c.fp(t_ref).y(), c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near start of and outside curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.001);
      norm << c.fp(t_ref).y(), -c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near start of and far outside curve
      dist_ref=3;
      t_ref=static_cast<data_type>(0.001);
      norm << c.fp(t_ref).y(), -c.fp(t_ref).x();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));
    }

    void point_smooth_3d_test()
    {
      point_type3 cntrl_in[4];

      // set control points
      cntrl_in[0] <<-1, 2, 1;
      cntrl_in[1] << 0, 1, 0;
      cntrl_in[2] << 3, 0, 1;
      cntrl_in[3] << 4, 1, 2;

      curve_type3 c(3);
      point_type3 pt, fp, norm;
      data_type  dist, t, dist_ref, t_ref, t_guess;

      // set control points
      for (index_type2 i=0; i<4; ++i)
      {
        c.set_control_point(cntrl_in[i], i);
      }

      // test point on curve
      dist_ref=0;
      t_ref=0.25;
      fp=c.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1;
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point very near curve
      dist_ref=static_cast<data_type>(0.01);
      t_ref=0.25;
      fp=c.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1;
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=0.25;
      fp=c.fp(t_ref);
      norm << fp.z(),-fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1;
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point far from curve
      dist_ref=static_cast<data_type>(1.5);
      t_ref=0.25;
      fp=c.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1;
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point on curve
      dist_ref=0;
      t_ref=static_cast<data_type>(0.6);
      fp=c.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=0;
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1;
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.65);
      fp=c.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=0;
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=1;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near end of curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.01);
      fp=c.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-t_ref/2;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1;
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point very near end of curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.001);
      fp=c.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-t_ref/2;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1;
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point very near end of curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.999);
      fp=c.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+(1-t_ref)/2;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=0;
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=1;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point beyond start of curve
      t_ref=static_cast<data_type>(0);
      pt << -2, 2, 3;
      dist_ref=(cntrl_in[0]-pt).norm();

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=t_ref+static_cast<data_type>(0.2);
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1;
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point beyond end of curve
      t_ref=static_cast<data_type>(1);
      pt << 5, 2, 1;
      dist_ref=(cntrl_in[3]-pt).norm();

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=t_ref-static_cast<data_type>(0.2);
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=0;
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=1;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));
    }

    void point_closed_3d_test()
    {
      point_type3 cntrl_in[13];

      // set control points
      cntrl_in[0]  <<   1, 0,   0;
      cntrl_in[1]  <<   1, 0.5,-0.5;
      cntrl_in[2]  << 0.5, 1,  -0.5;
      cntrl_in[3]  <<   0, 1,   0;
      cntrl_in[4]  <<-0.5, 1,   0;
      cntrl_in[5]  <<  -1, 0.5, 0.5;
      cntrl_in[6]  <<  -1, 0,   0.5;
      cntrl_in[7]  <<  -1,-0.5, 0;
      cntrl_in[8]  <<-0.5,-1,  -0.5;
      cntrl_in[9]  <<   0,-1,   0;
      cntrl_in[10] << 0.5,-1,   0.5;
      cntrl_in[11] <<   1,-0.5, 0.5;
      cntrl_in[12] <<   1,0,    0;

      curve_type3 c(12);
      point_type3 pt, norm, fp;
      data_type  dist, t, dist_ref, t_ref, t_guess;

      // set control points
      for (index_type3 i=0; i<13; ++i)
      {
        c.set_control_point(cntrl_in[i], i);
      }

      // test point on curve
      dist_ref=0;
      t_ref=0.25;
      fp=c.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Newton's method does not converge.
//      t_guess=t_ref-static_cast<data_type>(0.2);
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=1;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=0.25;
      fp=c.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Newton's method does not converge.
//      t_guess=0;
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=1;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near center
      dist_ref=static_cast<data_type>(0.77);
      t_ref=0.25;
      fp=c.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Newton's method does not converge.
//      t_guess=t_ref-static_cast<data_type>(0.2);
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Newton's method does not converge.
//      t_guess=0;
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Newton's method does not converge.
//      t_guess=1;
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near and outside curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.7);
      fp=c.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Newton's method does not converge.
//      t_guess=t_ref-static_cast<data_type>(0.2);
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=1;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point far and outside curve
      dist_ref=3;
      t_ref=static_cast<data_type>(0.7);
      fp=c.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Newton's method does not converge.
//      t_guess=t_ref+static_cast<data_type>(0.2);
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Newton's method does not converge.
//      t_guess=t_ref-static_cast<data_type>(0.2);
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Newton's method does not converge.
//      t_guess=0;
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Newton's method does not converge.
//      t_guess=1;
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near end of curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.999);
      fp=c.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+(1-t_ref)/2;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Newton's method does not converge.
//      t_guess=t_ref-static_cast<data_type>(0.2);
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=1;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near end of and outside curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.999);
      fp=c.fp(t_ref);
      norm << -fp.z(), fp.z(), fp.x()-fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+(1-t_ref)/2;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Newton's method does not converge.
//      t_guess=t_ref-static_cast<data_type>(0.2);
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=1;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near start of curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.001);
      fp=c.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Newton's method does not converge.
//      t_guess=t_ref+static_cast<data_type>(0.2);
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-t_ref/2;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=1;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near start of and outside curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.001);
      fp=c.fp(t_ref);
      norm << -fp.z(), fp.z(), fp.x()-fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Newton's method does not converge.
//      t_guess=t_ref+static_cast<data_type>(0.2);
//      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-t_ref/2;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=1;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near start of and far outside curve
      dist_ref=3;
      t_ref=static_cast<data_type>(0.001);
      fp=c.fp(t_ref);
      norm << -fp.z(), fp.z(), fp.x()-fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-t_ref/2;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=1;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, c, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));
//       if (typeid(data_type)==typeid(double))
//       {
//         std::cout << "c_f(t_ref)=" << c.f(t_ref) << "\tpt=" << pt << std::endl;
//         std::cout << "dist=" << dist << "\tdist_ref=" << dist_ref << "\tt=" << t << "\tt_ref=" << t_ref << std::endl;
//         std::cout << "dist to end=" << (cntrl_in[0]-pt).norm() << std::endl;
//         std::vector<point_type3> vec(2);
//         vec[0]=pt;
//         vec[1]=c.f(t);
//         octave_print(1, vec, c);
//       }
    }

    void point_piecewise_01_smooth_3d_test()
    {
      point_type3 cntrl_in[4];

      // set control points
      cntrl_in[0] <<-1, 2, 1;
      cntrl_in[1] << 0, 1, 0;
      cntrl_in[2] << 3, 0, 1;
      cntrl_in[3] << 4, 1, 2;

      piecewise_curve_type3 pwc, pwcsave;
      curve_type3 c(3);
      point_type3 pt, fp, norm;
      data_type  dist, t, dist_ref, t_ref, t_guess, t_split;
      typename piecewise_curve_type3::error_code err;

      // set control points
      for (index_type2 i=0; i<4; ++i)
      {
        c.set_control_point(cntrl_in[i], i);
      }

      err=pwc.push_back(c);
      TEST_ASSERT(err==piecewise_curve_type3::NO_ERRORS);

      pwcsave=pwc;

      // test point near curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=0.25;
      fp=pwc.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=pwc.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1;
//      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, pwc, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_split=t_ref;
      pwc.split(t_split);

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split+std::numeric_limits<data_type>::epsilon();
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split-std::numeric_limits<data_type>::epsilon();
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1;
//      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, pwc, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_split=t_ref-static_cast<data_type>(0.05);
      pwc=pwcsave;
      pwc.split(t_split);

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split+std::numeric_limits<data_type>::epsilon();
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split-std::numeric_limits<data_type>::epsilon();
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1;
//      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, pwc, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_split=t_ref+static_cast<data_type>(0.05);
      pwc=pwcsave;
      pwc.split(t_split);

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split+std::numeric_limits<data_type>::epsilon();
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split-std::numeric_limits<data_type>::epsilon();
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1;
//      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, pwc, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      pwcsave=pwc;

      pwc.split(static_cast<data_type>(0.1));
      pwc.split(static_cast<data_type>(0.2));
      pwc.split(static_cast<data_type>(0.3));
      pwc.split(static_cast<data_type>(0.4));
      pwc.split(static_cast<data_type>(0.5));
      pwc.split(static_cast<data_type>(0.6));
      pwc.split(static_cast<data_type>(0.7));
      pwc.split(static_cast<data_type>(0.8));
      pwc.split(static_cast<data_type>(0.9));

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1;
//      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, pwc, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));
    }

    void point_piecewise_trange_smooth_3d_test()
    {
      point_type3 cntrl_in[4];

      // set control points
      cntrl_in[0] <<-1, 2, 1;
      cntrl_in[1] << 0, 1, 0;
      cntrl_in[2] << 3, 0, 1;
      cntrl_in[3] << 4, 1, 2;

      piecewise_curve_type3 pwc, pwcsave;
      curve_type3 c(3);
      point_type3 pt, fp, norm;
      data_type  dist, t, dist_ref, t_ref, t_guess, t_split, t0;
      typename piecewise_curve_type3::error_code err;

      // set control points
      for (index_type2 i=0; i<4; ++i)
      {
        c.set_control_point(cntrl_in[i], i);
      }

      err=pwc.push_back(c);
      TEST_ASSERT(err==piecewise_curve_type3::NO_ERRORS);

      // pwc.parameter_report();

      t0=static_cast<data_type>(1.6);
      pwc.set_t0(t0);

      // pwc.parameter_report();

      pwcsave=pwc;

      // test point near curve
      dist_ref=static_cast<data_type>(0.1);
      t_ref=static_cast<data_type>(0.25)+t0;
      fp=pwc.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=pwc.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0+t0;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1+t0;
//      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, pwc, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_split=t_ref;
      pwc.split(t_split);

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split+std::numeric_limits<data_type>::epsilon();
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split-std::numeric_limits<data_type>::epsilon();
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0+t0;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1+t0;
//      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, pwc, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_split=t_ref-static_cast<data_type>(0.05);
      pwc=pwcsave;
      pwc.split(t_split);

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split+std::numeric_limits<data_type>::epsilon();
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split-std::numeric_limits<data_type>::epsilon();
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0+t0;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1+t0;
//      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, pwc, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_split=t_ref+static_cast<data_type>(0.05);
      pwc=pwcsave;
      pwc.split(t_split);

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split+std::numeric_limits<data_type>::epsilon();
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_split-std::numeric_limits<data_type>::epsilon();
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0+t0;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1+t0;
//      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, pwc, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      pwcsave=pwc;

      pwc.split(static_cast<data_type>(0.1)+t0);
      pwc.split(static_cast<data_type>(0.2)+t0);
      pwc.split(static_cast<data_type>(0.3)+t0);
      pwc.split(static_cast<data_type>(0.4)+t0);
      pwc.split(static_cast<data_type>(0.5)+t0);
      pwc.split(static_cast<data_type>(0.6)+t0);
      pwc.split(static_cast<data_type>(0.7)+t0);
      pwc.split(static_cast<data_type>(0.8)+t0);
      pwc.split(static_cast<data_type>(0.9)+t0);

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref+static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=t_ref-static_cast<data_type>(0.2);
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      t_guess=0+t0;
      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// Case fails because Newton's method seeks local maximum.
//      t_guess=1+t0;
//      dist=eli::geom::intersect::minimum_distance(t, pwc, pt, t_guess);
//      TEST_ASSERT(tol.approximately_equal(t, t_ref));
//      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(t, pwc, pt);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

    }

    void dist_surf_test()
    {
      point_type3 cntrl_in[4];

      // set control points
      cntrl_in[0] <<-1, 2, 1;
      cntrl_in[1] << 0, 1, 0;
      cntrl_in[2] << 3, 0, 1;
      cntrl_in[3] << 4, 1, 2;

      curve_type3 c(3);
      point_type3 pt, fp, norm;
      data_type  dist, t, dist_ref, t_ref, t_guess;

      // set control points
      for (index_type2 i=0; i<4; ++i)
      {
        c.set_control_point(cntrl_in[i], i);
      }

      // test point on curve
      dist_ref=0;
      t_ref=0.25;
      fp=c.fp(t_ref);
      norm << fp.z(), -fp.z(), -fp.x()+fp.y();
      norm.normalize();
      pt=c.f(t_ref)+dist_ref*norm;

      t_guess=t_ref;
      dist=eli::geom::intersect::minimum_distance(t, c, pt, t_guess);
      TEST_ASSERT(tol.approximately_equal(t, t_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));


      curve_type1 ans;

      ans = c.mindistcurve( pt );

//      if (typeid(data_type)==typeid(double))
//      {
//        octave_print( 1, ans );
//      }

    }

};

#endif

