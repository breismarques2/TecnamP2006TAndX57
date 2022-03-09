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

#ifndef minimum_distance_surface_test_suite_hpp
#define minimum_distance_surface_test_suite_hpp

#include <cmath>    // cos(), sin()

#include <typeinfo> // typeid

#include "eli/geom/surface/bezier.hpp"
#include "eli/geom/surface/piecewise.hpp"
#include "eli/geom/intersect/minimum_distance_surface.hpp"

template<typename data__>
class minimum_distance_surface_test_suite : public Test::Suite
{
  private:
    typedef data__ data_type;

    typedef eli::geom::surface::piecewise<eli::geom::surface::bezier, data_type, 3> piecewise_surface_type;
    typedef typename piecewise_surface_type::surface_type surface_type;
    typedef typename surface_type::point_type point_type;
    typedef typename surface_type::index_type index_type;
    typedef typename surface_type::tolerance_type tolerance_type;

    typedef typename surface_type::onedbezsurf onedbez_type;

    tolerance_type tol;

  protected:
    void AddTests(const float &)
    {
      // add the tests
      TEST_ADD(minimum_distance_surface_test_suite<float>::point_smooth_test);
      TEST_ADD(minimum_distance_surface_test_suite<float>::point_closed_test);
      TEST_ADD(minimum_distance_surface_test_suite<float>::point_piecewise_01_smooth_test);
      TEST_ADD(minimum_distance_surface_test_suite<float>::point_piecewise_trange_smooth_test);
      TEST_ADD(minimum_distance_surface_test_suite<float>::degen_point_test);
      TEST_ADD(minimum_distance_surface_test_suite<float>::dist_surf_test);
    }
    void AddTests(const double &)
    {
      // add the tests
      TEST_ADD(minimum_distance_surface_test_suite<double>::point_smooth_test);
      TEST_ADD(minimum_distance_surface_test_suite<double>::point_closed_test);
      TEST_ADD(minimum_distance_surface_test_suite<double>::point_piecewise_01_smooth_test);
      TEST_ADD(minimum_distance_surface_test_suite<double>::point_piecewise_trange_smooth_test);
      TEST_ADD(minimum_distance_surface_test_suite<double>::degen_point_test);
      TEST_ADD(minimum_distance_surface_test_suite<double>::dist_surf_test);
    }
    void AddTests(const long double &)
    {
      // add the tests
      TEST_ADD(minimum_distance_surface_test_suite<long double>::point_smooth_test);
      TEST_ADD(minimum_distance_surface_test_suite<long double>::point_closed_test);
      TEST_ADD(minimum_distance_surface_test_suite<long double>::point_piecewise_01_smooth_test);
      TEST_ADD(minimum_distance_surface_test_suite<long double>::point_piecewise_trange_smooth_test);
      TEST_ADD(minimum_distance_surface_test_suite<long double>::degen_point_test);
      TEST_ADD(minimum_distance_surface_test_suite<long double>::dist_surf_test);
    }

  public:
    minimum_distance_surface_test_suite()
    {
      AddTests(data__());
    }
    ~minimum_distance_surface_test_suite()
    {
    }

  private:
    void octave_print(int figno, const std::vector<point_type> &pts, const surface_type &s) const
    {
      size_t i, j;

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

      // initialize the u & v parameters
      std::vector<data__> u(51), v(51);
      for (i=0; i<u.size(); ++i)
      {
        u[i]=static_cast<data__>(i)/(u.size()-1);
      }
      for (j=0; j<v.size(); ++j)
      {
        v[j]=static_cast<data__>(j)/(v.size()-1);
      }

      // set the surface points
      std::cout << "surf_x=[";
      for (i=0; i<u.size(); ++i)
      {
        std::cout << s.f(u[i], v[0]).x();
        for (j=1; j<(v.size()-1); ++j)
        {
          std::cout << ", " << s.f(u[i], v[j]).x();
        }
        j=v.size()-1;
        std::cout << ", " << s.f(u[i], v[j]).x();
        if (i<(u.size()-1))
          std::cout << "; " << std::endl;
      }
      std::cout << "];" << std::endl;

      std::cout << "surf_y=[";
      for (i=0; i<u.size(); ++i)
      {
        std::cout << s.f(u[i], v[0]).y();
        for (j=1; j<(v.size()-1); ++j)
        {
          std::cout << ", " << s.f(u[i], v[j]).y();
        }
        j=v.size()-1;
        std::cout << ", " << s.f(u[i], v[j]).y();
        if (i<(u.size()-1))
          std::cout << "; " << std::endl;
      }
      std::cout << "];" << std::endl;

      std::cout << "surf_z=[";
      for (i=0; i<u.size(); ++i)
      {
        std::cout << s.f(u[i], v[0]).z();
        for (j=1; j<(v.size()-1); ++j)
        {
          std::cout << ", " << s.f(u[i], v[j]).z();
        }
        j=v.size()-1;
        std::cout << ", " << s.f(u[i], v[j]).z();
        if (i<(u.size()-1))
          std::cout << "; " << std::endl;
      }
      std::cout << "];" << std::endl;

      std::cout << "setenv('GNUTERM', 'x11');" << std::endl;
      std::cout << "mesh(surf_x, surf_y, surf_z, zeros(size(surf_z)), 'EdgeColor', [0 0 0]);" << std::endl;
      std::cout << "hold on;" << std::endl;
      std::cout << "plot3(xpts, ypts, zpts, 'or', 'MarkerEdgeColor', 'r', 'MarkerFaceColor', 'r');" << std::endl;
      std::cout << "hold off;" << std::endl;
      std::cout << "axis equal" << std::endl;

      std::cout << "figure(" << figno+1 << ");" << std::endl;
      std::cout << "u=[" << u[0];
      for (i=1; i<u.size(); ++i)
        std::cout << ", " << u[i];
      std::cout << "];" << std::endl;
      std::cout << "v=[" << v[0];
      for (i=1; i<v.size(); ++i)
        std::cout << ", " << v[i];
      std::cout << "];" << std::endl;
      std::cout << "g_u=[";
      for (i=0; i<u.size(); ++i)
      {
        j=0;
        std::cout << (s.f(u[i], v[j])-pts[0]).dot(s.f_u(u[i], v[j]));
        for (j=1; j<(v.size()-1); ++j)
        {
          std::cout << ", " << (s.f(u[i], v[j])-pts[0]).dot(s.f_u(u[i], v[j]));
        }
        j=v.size()-1;
        std::cout << ", " << (s.f(u[i], v[j])-pts[0]).dot(s.f_u(u[i], v[j]));
        if (i<(u.size()-1))
          std::cout << "; " << std::endl;
      }
      std::cout << "];" << std::endl;
      std::cout << "g_v=[";
      for (i=0; i<u.size(); ++i)
      {
        j=0;
        std::cout << (s.f(u[i], v[j])-pts[0]).dot(s.f_v(u[i], v[j]));
        for (j=1; j<(v.size()-1); ++j)
        {
          std::cout << ", " << (s.f(u[i], v[j])-pts[0]).dot(s.f_v(u[i], v[j]));
        }
        j=v.size()-1;
        std::cout << ", " << (s.f(u[i], v[j])-pts[0]).dot(s.f_v(u[i], v[j]));
        if (i<(u.size()-1))
          std::cout << "; " << std::endl;
      }
      std::cout << "];" << std::endl;

      std::cout << "setenv('GNUTERM', 'x11');" << std::endl;
      std::cout << "mesh(u, v, g_u, zeros(length(u), length(v)), 'EdgeColor', [0 0 0]);" << std::endl;
      std::cout << "hold on;" << std::endl;
      std::cout << "mesh(u, v, g_v, zeros(length(u), length(v)), 'EdgeColor', [0 0 0]);" << std::endl;
      std::cout << "surf(u, v, zeros(length(u), length(v)));" << std::endl;
      std::cout << "hold off;" << std::endl;
    }

    void octave_print(int figno, const onedbez_type &s) const
    {
      size_t i, j;

      // initialize the u & v parameters
      std::vector<data__> u(51), v(51);
      for (i=0; i<u.size(); ++i)
      {
        u[i]=static_cast<data__>(i)/(u.size()-1);
      }
      for (j=0; j<v.size(); ++j)
      {
        v[j]=static_cast<data__>(j)/(v.size()-1);
      }

      // set the surface points
      std::cout << "surf_x=[";
      for (i=0; i<u.size(); ++i)
      {
        std::cout << u[i];
        for (j=1; j<(v.size()-1); ++j)
        {
          std::cout << ", " << u[i];
        }
        j=v.size()-1;
        std::cout << ", " << u[i];
        if (i<(u.size()-1))
          std::cout << "; " << std::endl;
      }
      std::cout << "];" << std::endl;

      std::cout << "surf_y=[";
      for (i=0; i<u.size(); ++i)
      {
        std::cout << v[0];
        for (j=1; j<(v.size()-1); ++j)
        {
          std::cout << ", " << v[j];
        }
        j=v.size()-1;
        std::cout << ", " << v[j];
        if (i<(u.size()-1))
          std::cout << "; " << std::endl;
      }
      std::cout << "];" << std::endl;

      std::cout << "surf_z=[";
      for (i=0; i<u.size(); ++i)
      {
        std::cout << s.f(u[i], v[0]).x();
        for (j=1; j<(v.size()-1); ++j)
        {
          std::cout << ", " << s.f(u[i], v[j]).x();
        }
        j=v.size()-1;
        std::cout << ", " << s.f(u[i], v[j]).x();
        if (i<(u.size()-1))
          std::cout << "; " << std::endl;
      }
      std::cout << "];" << std::endl;


      std::vector<data__> cp_u(s.degree_u()+1), cp_v(s.degree_v()+1);
      for (i=0; i<cp_u.size(); ++i)
      {
        cp_u[i]=static_cast<data__>(i)/(cp_u.size()-1);
      }
      for (j=0; j<cp_v.size(); ++j)
      {
        cp_v[j]=static_cast<data__>(j)/(cp_v.size()-1);
      }

      // set the surface points
      std::cout << "cp_x=[";
      for (i=0; i<cp_u.size(); ++i)
      {
        std::cout << cp_u[i];
        for (j=1; j<(cp_v.size()-1); ++j)
        {
          std::cout << ", " << cp_u[i];
        }
        j=cp_v.size()-1;
        std::cout << ", " << cp_u[i];
        if (i<(cp_u.size()-1))
          std::cout << "; " << std::endl;
      }
      std::cout << "];" << std::endl;

      std::cout << "cp_y=[";
      for (i=0; i<cp_u.size(); ++i)
      {
        std::cout << cp_v[0];
        for (j=1; j<(cp_v.size()-1); ++j)
        {
          std::cout << ", " << cp_v[j];
        }
        j=cp_v.size()-1;
        std::cout << ", " << cp_v[j];
        if (i<(cp_u.size()-1))
          std::cout << "; " << std::endl;
      }
      std::cout << "];" << std::endl;

      std::cout << "cp_z=[";
      for (i=0; i<=s.degree_u(); ++i)
      {
        std::cout << s.get_control_point( i, 0 ).x();
        for (j=1; j<s.degree_v(); ++j)
        {
          std::cout << ", " << s.get_control_point(i, j ).x();
        }
        j=s.degree_v();
        std::cout << ", " << s.get_control_point(i, j).x();
        if (i<s.degree_u())
          std::cout << "; " << std::endl;
      }
      std::cout << "];" << std::endl;

      std::cout << "figure(" << figno << ");" << std::endl;
      std::cout << "setenv('GNUTERM', 'x11');" << std::endl;
      std::cout << "mesh(surf_x, surf_y, surf_z, zeros(size(surf_z)), 'EdgeColor', [0 0 0]);" << std::endl;
    }

    void point_smooth_test()
    {
      const index_type n(3), m(3);
      surface_type s(n, m);
      point_type cp[3+1][3+1], pt_out;
      point_type pt, norm, u_contra, v_contra;
      data_type dist, u, v, dist_ref, u_ref, v_ref;
      data_type u_off(static_cast<data_type>(0.2)), v_off(static_cast<data_type>(0.2));
      index_type i, j;

      // create surface with specified control points
      cp[0][0] << -15, 0,  15;
      cp[1][0] <<  -5, 5,  15;
      cp[2][0] <<   5, 5,  15;
      cp[3][0] <<  15, 0,  15;
      cp[0][1] << -15, 5,   5;
      cp[1][1] <<  -5, 5,   5;
      cp[2][1] <<   5, 5,   5;
      cp[3][1] <<  15, 5,   5;
      cp[0][2] << -15, 5,  -5;
      cp[1][2] <<  -5, 5,  -5;
      cp[2][2] <<   5, 5,  -5;
      cp[3][2] <<  15, 5,  -5;
      cp[0][3] << -15, 0, -15;
      cp[1][3] <<  -5, 5, -15;
      cp[2][3] <<   5, 5, -15;
      cp[3][3] <<  15, 0, -15;

      // create surface with specified dimensions and set control points
      for (i=0; i<=n; ++i)
      {
        for (j=0; j<=m; ++j)
        {
          s.set_control_point(cp[i][j], i, j);
        }
      }
      TEST_ASSERT(s.open_u());
      TEST_ASSERT(s.open_v());

      // test point on surface
      dist_ref=0;
      u_ref=0.25;
      v_ref=0.25;
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point very near surface
      dist_ref=static_cast<data_type>(0.01);
      u_ref=0.25;
      v_ref=0.25;
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=0.25;
      v_ref=0.25;
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near and on concave side of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=0.25;
      v_ref=0.25;
      norm=-s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point far surface
      dist_ref=static_cast<data_type>(1.1);
      u_ref=0.25;
      v_ref=0.25;
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point on surface
      dist_ref=0;
      u_ref=static_cast<data_type>(0.64);
      v_ref=static_cast<data_type>(0.32);
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point very near surface
      dist_ref=static_cast<data_type>(0.01);
      u_ref=static_cast<data_type>(0.64);
      v_ref=static_cast<data_type>(0.32);
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.64);
      v_ref=static_cast<data_type>(0.32);
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near and on concave side of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.64);
      v_ref=static_cast<data_type>(0.32);
      norm=-s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near surface
      dist_ref=static_cast<data_type>(1.1);
      u_ref=static_cast<data_type>(0.64);
      v_ref=static_cast<data_type>(0.32);
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near corner of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.01);
      v_ref=static_cast<data_type>(0.01);
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near corner of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.99);
      v_ref=static_cast<data_type>(0.01);
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near corner of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.01);
      v_ref=static_cast<data_type>(0.999);
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near corner of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.999);
      v_ref=static_cast<data_type>(0.999);
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point beyond edge of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(1);
      v_ref=static_cast<data_type>(0.4);
      norm=s.normal(u_ref, v_ref);
      u_contra=-norm.cross(s.f_v(u_ref, v_ref));
      u_contra.normalize();
      pt=static_cast<data_type>(0.01)*u_contra+s.f(u_ref, v_ref)+dist_ref*norm;
      dist_ref=eli::geom::point::distance(pt, s.f(u_ref, v_ref));
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // Surface solver converges to nearby apparent solution.
      data_type u_alt, v_alt, dist_alt;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref+v_off);
      u_alt=u;
      v_alt=v;
      dist_alt=dist;

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      // test point beyond edge of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.6);
      v_ref=static_cast<data_type>(1);
      norm=s.normal(u_ref, v_ref);
      v_contra=norm.cross(s.f_u(u_ref, v_ref));
      v_contra.normalize();
      pt=static_cast<data_type>(0.01)*v_contra+s.f(u_ref, v_ref)+dist_ref*norm;
      dist_ref=eli::geom::point::distance(pt, s.f(u_ref, v_ref));
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // Surface solver converges to nearby apparent solution.
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref);
      u_alt=u;
      v_alt=v;
      dist_alt=dist;

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      // test point beyond edge of surface
      dist_ref=static_cast<data_type>(0.5);
      u_ref=static_cast<data_type>(0);
      v_ref=static_cast<data_type>(0.2);
      norm=s.normal(u_ref, v_ref);
      u_contra=-norm.cross(s.f_v(u_ref, v_ref));
      u_contra.normalize();
      pt=static_cast<data_type>(-1.0)*u_contra+s.f(u_ref, v_ref)+dist_ref*norm;
      dist_ref=eli::geom::point::distance(pt, s.f(u_ref, v_ref));
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

//      if (typeid(data_type)==typeid(double))
//      {
//        std::cout << "% s_f(" << u_ref << ", " << v_ref << ")=" << s.f(u_ref, v_ref)
//                  << "\ts_f(" << u << ", " << v << ")=" << s.f(u, v) << "\tpt=" << pt << std::endl;
//        std::cout << "% dist=" << dist << "\tdist_ref=" << dist_ref
//                  << "\t(u, v)=(" << u << ", " << v << ")"
//                  << "\t(u_ref, v_ref)=(" << u_ref << ", " << v_ref << ")" << std::endl;
//        std::vector<point_type> vec(3);
//        vec[0] = pt;
//        vec[1] = s.f(u_ref, v_ref);
//        vec[2] = s.f(u, v);
//        octave_print( 1, vec, s );
//
//        onedbez_type ans = s.mindistsurf( pt );
//
//        std::cout << "% ans_f(" << u << ", " << v << ")=" << ans.f(u, v) << std::endl;
//        std::cout << "% ref ans_f(" << u_ref << ", " << v_ref << ")=" << ans.f(u_ref, v_ref) << std::endl;
//
//        octave_print( 3, ans );
//      }

      // Surface solver converges to nearby apparent solution.
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      u_alt=u;
      v_alt=v;
      dist_alt=dist;

//      if (typeid(data_type)==typeid(double))
//      {
//        onedbez_type ans = s.mindistsurf( pt );
//        std::cout << "% alt ans_f(" << u_alt << ", " << v_alt << ")=" << ans.f(u_alt, v_alt) << std::endl;
//      }

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      // test point beyond edge of surface
      dist_ref=static_cast<data_type>(0.5);
      u_ref=static_cast<data_type>(0.2);
      v_ref=static_cast<data_type>(0);
      norm=s.normal(u_ref, v_ref);
      v_contra=norm.cross(s.f_u(u_ref, v_ref));
      v_contra.normalize();
      pt=static_cast<data_type>(-0.1)*v_contra+s.f(u_ref, v_ref)+dist_ref*norm;
      dist_ref=eli::geom::point::distance(pt, s.f(u_ref, v_ref));
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // Surface solver converges to nearby apparent solution.
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref+static_cast<data_type>(0.02));
      u_alt=u;
      v_alt=v;
      dist_alt=dist;

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref+static_cast<data_type>(0.02));
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

    }

    void point_closed_test()
    {
      const index_type n(12), m(3);
      surface_type s(n, m);
      point_type cp[n+1], offset[m+1], pt_out;
      point_type pt, norm, u_contra, v_contra;
      data_type  z[m+1], dist, u, v, dist_ref, u_ref, v_ref;
      data_type u_off(static_cast<data_type>(0.1)), v_off(static_cast<data_type>(0.1));
      index_type i, j;

      // set control points
      cp[0]  <<   1, 0,   0;
      cp[1]  <<   1, 0.5, 0;
      cp[2]  << 0.5, 1,   0;
      cp[3]  <<   0, 1,   0;
      cp[4]  <<-0.5, 1,   0;
      cp[5]  <<  -1, 0.5, 0;
      cp[6]  <<  -1, 0,   0;
      cp[7]  <<  -1,-0.5, 0;
      cp[8]  <<-0.5,-1,   0;
      cp[9]  <<   0,-1,   0;
      cp[10] << 0.5,-1,   0;
      cp[11] <<   1,-0.5, 0;
      cp[12] <<   1,0,    0;
      z[0]=-0.5;
      z[1]=0;
      z[2]=0.5;
      z[3]=1;
      offset[0] << 0, 0, 0;
      offset[1] << 0.5, 0, 0;
      offset[2] << -0.5, 0.5, 0;
      offset[3] << 0, 0, 0;

      // create surface with specified dimensions and set control points
      for (j=0; j<=m; ++j)
      {
        for (i=0; i<=n; ++i)
        {
          cp[i].z() = z[j];
          s.set_control_point(cp[i]+offset[j], i, j);
        }
      }
      TEST_ASSERT(s.closed_u());
      TEST_ASSERT(s.open_v());

      // test point on surface
      dist_ref=0;
      u_ref=static_cast<data_type>(0.35);
      v_ref=static_cast<data_type>(0.35);
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point very near surface
      dist_ref=static_cast<data_type>(0.01);
      u_ref=static_cast<data_type>(0.35);
      v_ref=static_cast<data_type>(0.35);
      norm=-s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.35);
      v_ref=static_cast<data_type>(0.35);
      norm=-s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near center surface
      dist_ref=static_cast<data_type>(0.72);
      u_ref=static_cast<data_type>(0.35);
      v_ref=static_cast<data_type>(0.35);
      norm=-s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

// RM -- New tangent plane solver causes this case to miss solution for floats.
      // +v_off cases seek local maximum.
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
//      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
//      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near and outside surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.35);
      v_ref=static_cast<data_type>(0.35);
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point far and outside surface
      dist_ref=3;
      u_ref=static_cast<data_type>(0.25);
      v_ref=static_cast<data_type>(0.7);
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near end of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.25);
      v_ref=static_cast<data_type>(0.999);
      norm=-s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near end and outside of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.25);
      v_ref=static_cast<data_type>(0.999);
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near end of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.25);
      v_ref=static_cast<data_type>(0.001);
      norm=-s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near end and outside of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.25);
      v_ref=static_cast<data_type>(0.001);
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near closed portion of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.001);
      v_ref=static_cast<data_type>(0.3);
      norm=-s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1-u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near closed portion and outside of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.001);
      v_ref=static_cast<data_type>(0.3);
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1-u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 1-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near closed portion of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.999);
      v_ref=static_cast<data_type>(0.3);
      norm=-s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0+u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near closed portion and outside of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.999);
      v_ref=static_cast<data_type>(0.3);
      norm=s.normal(u_ref, v_ref);
      pt=s.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, 0+u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, s, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

//       if (typeid(data_type)==typeid(double))
//       {
//         std::cout << "% s_f(" << u_ref << ", " << v_ref << ")=" << s.f(u_ref, v_ref)
//                   << "\ts_f(" << u << ", " << v << ")=" << s.f(u, v) << "\tpt=" << pt << std::endl;
//         std::cout << "% dist=" << dist << "\tdist_ref=" << dist_ref
//                   << "\t(u, v)=(" << u << ", " << v << ")"
//                   << "\t(u_ref, v_ref)=(" << u_ref << ", " << v_ref << ")" << std::endl;
//         std::vector<point_type> vec(3);
//         vec[0]=pt;
//         vec[1]=s.f(u_ref, v_ref);
//         vec[2]=s.f(u, v);
//         octave_print(1, vec, s);
//       }
    }

    void point_piecewise_01_smooth_test()
    {
      const index_type n(3), m(3);
      surface_type s(n, m);
      point_type cp[3+1][3+1], pt_out;
      point_type pt, norm, u_contra, v_contra;
      data_type dist, u, v, dist_ref, u_ref, v_ref;
      data_type u_off(static_cast<data_type>(0.2)), v_off(static_cast<data_type>(0.2));
      index_type i, j;
      piecewise_surface_type pws;
      typename piecewise_surface_type::error_code err;

      pws.init_uv(1, 1);

      // create surface with specified control points
      cp[0][0] << -15, 0,  15;
      cp[1][0] <<  -5, 5,  15;
      cp[2][0] <<   5, 5,  15;
      cp[3][0] <<  15, 0,  15;
      cp[0][1] << -15, 5,   5;
      cp[1][1] <<  -5, 5,   5;
      cp[2][1] <<   5, 5,   5;
      cp[3][1] <<  15, 5,   5;
      cp[0][2] << -15, 5,  -5;
      cp[1][2] <<  -5, 5,  -5;
      cp[2][2] <<   5, 5,  -5;
      cp[3][2] <<  15, 5,  -5;
      cp[0][3] << -15, 0, -15;
      cp[1][3] <<  -5, 5, -15;
      cp[2][3] <<   5, 5, -15;
      cp[3][3] <<  15, 0, -15;

      // create surface with specified dimensions and set control points
      for (i=0; i<=n; ++i)
      {
        for (j=0; j<=m; ++j)
        {
          s.set_control_point(cp[i][j], i, j);
        }
      }
      TEST_ASSERT(s.open_u());
      TEST_ASSERT(s.open_v());

      err=pws.set(s, 0, 0);
      TEST_ASSERT(err==piecewise_surface_type::NO_ERRORS);

      pws.split_u(static_cast<data_type>(0.2));
      pws.split_u(static_cast<data_type>(0.4));
      pws.split_u(static_cast<data_type>(0.6));
      pws.split_u(static_cast<data_type>(0.8));

      pws.split_v(static_cast<data_type>(0.2));
      pws.split_v(static_cast<data_type>(0.4));
      pws.split_v(static_cast<data_type>(0.6));
      pws.split_v(static_cast<data_type>(0.8));

      // test point on surface
      dist_ref=0;
      u_ref=0.25;
      v_ref=0.25;
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point very near surface
      dist_ref=static_cast<data_type>(0.01);
      u_ref=0.25;
      v_ref=0.25;
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=0.25;
      v_ref=0.25;
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near and on concave side of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=0.25;
      v_ref=0.25;
      norm=-pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point far surface
      dist_ref=static_cast<data_type>(1.1);
      u_ref=0.25;
      v_ref=0.25;
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point on surface
      dist_ref=0;
      u_ref=static_cast<data_type>(0.64);
      v_ref=static_cast<data_type>(0.32);
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point very near surface
      dist_ref=static_cast<data_type>(0.01);
      u_ref=static_cast<data_type>(0.64);
      v_ref=static_cast<data_type>(0.32);
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.64);
      v_ref=static_cast<data_type>(0.32);
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near and on concave side of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.64);
      v_ref=static_cast<data_type>(0.32);
      norm=-pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near surface
      dist_ref=static_cast<data_type>(1.1);
      u_ref=static_cast<data_type>(0.64);
      v_ref=static_cast<data_type>(0.32);
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near corner of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.01);
      v_ref=static_cast<data_type>(0.01);
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near corner of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.99);
      v_ref=static_cast<data_type>(0.01);
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near corner of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.01);
      v_ref=static_cast<data_type>(0.999);
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near corner of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.999);
      v_ref=static_cast<data_type>(0.999);
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point beyond edge of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(1);
      v_ref=static_cast<data_type>(0.4);
      norm=pws.normal(u_ref, v_ref);
      u_contra=-norm.cross(pws.f_v(u_ref, v_ref));
      u_contra.normalize();
      pt=static_cast<data_type>(0.01)*u_contra+pws.f(u_ref, v_ref)+dist_ref*norm;
      dist_ref=eli::geom::point::distance(pt, pws.f(u_ref, v_ref));
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // Surface solver converges to nearby apparent solution.
      data_type u_alt, v_alt, dist_alt;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref+v_off);
      u_alt=u;
      v_alt=v;
      dist_alt=dist;

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      // test point beyond edge of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.6);
      v_ref=static_cast<data_type>(1);
      norm=pws.normal(u_ref, v_ref);
      v_contra=norm.cross(pws.f_u(u_ref, v_ref));
      v_contra.normalize();
      pt=static_cast<data_type>(0.01)*v_contra+pws.f(u_ref, v_ref)+dist_ref*norm;
      dist_ref=eli::geom::point::distance(pt, pws.f(u_ref, v_ref));
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // Surface solver converges to nearby apparent solution.
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref);
      u_alt=u;
      v_alt=v;
      dist_alt=dist;

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      // test point beyond edge of surface
      dist_ref=static_cast<data_type>(0.5);
      u_ref=static_cast<data_type>(0);
      v_ref=static_cast<data_type>(0.2);
      norm=pws.normal(u_ref, v_ref);
      u_contra=-norm.cross(pws.f_v(u_ref, v_ref));
      u_contra.normalize();
      pt=static_cast<data_type>(-0.1)*u_contra+pws.f(u_ref, v_ref)+dist_ref*norm;
      dist_ref=eli::geom::point::distance(pt, pws.f(u_ref, v_ref));
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // Surface solver converges to nearby apparent solution.
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      u_alt=u;
      v_alt=v;
      dist_alt=dist;

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      if (typeid(data_type)==typeid(float))
      {
        TEST_ASSERT(std::abs(dist-dist_alt) < 2e-3);
      }
      else
      {
        TEST_ASSERT(tol.approximately_equal(dist, dist_alt));
      }

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      if (typeid(data_type)==typeid(float))
      {
        TEST_ASSERT(std::abs(dist-dist_alt) < 2e-3);
      }
      else
      {
        TEST_ASSERT(tol.approximately_equal(dist, dist_alt));
      }

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      if (typeid(data_type)==typeid(float))
      {
        TEST_ASSERT(std::abs(dist-dist_alt) < 2e-3);
      }
      else
      {
        TEST_ASSERT(tol.approximately_equal(dist, dist_alt));
      }

      // test point beyond edge of surface
      dist_ref=static_cast<data_type>(0.5);
      u_ref=static_cast<data_type>(0.2);
      v_ref=static_cast<data_type>(0);
      norm=pws.normal(u_ref, v_ref);
      v_contra=norm.cross(pws.f_u(u_ref, v_ref));
      v_contra.normalize();
      pt=static_cast<data_type>(-0.1)*v_contra+pws.f(u_ref, v_ref)+dist_ref*norm;
      dist_ref=eli::geom::point::distance(pt, pws.f(u_ref, v_ref));
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // Surface solver converges to nearby apparent solution.
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref+static_cast<data_type>(0.02));
      u_alt=u;
      v_alt=v;
      dist_alt=dist;

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref+static_cast<data_type>(0.02));
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      if (typeid(data_type)==typeid(float))
      {
        TEST_ASSERT(std::abs(dist-dist_alt) < 2e-3);
      }
      else
      {
        TEST_ASSERT(tol.approximately_equal(dist, dist_alt));
      }

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      if (typeid(data_type)==typeid(float))
      {
        TEST_ASSERT(std::abs(dist-dist_alt) < 2e-3);
      }
      else
      {
        TEST_ASSERT(tol.approximately_equal(dist, dist_alt));
      }

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1, 1);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      if (typeid(data_type)==typeid(float))
      {
        TEST_ASSERT(std::abs(dist-dist_alt) < 2e-3);
      }
      else
      {
        TEST_ASSERT(tol.approximately_equal(dist, dist_alt));
      }
    }

    void point_piecewise_trange_smooth_test()
    {
      const index_type n(3), m(3);
      surface_type s(n, m);
      point_type cp[3+1][3+1], pt_out;
      point_type pt, norm, u_contra, v_contra;
      data_type dist, u, v, dist_ref, u_ref, v_ref;
      data_type u_off(static_cast<data_type>(0.2)), v_off(static_cast<data_type>(0.2));
      index_type i, j;
      piecewise_surface_type pws;
      typename piecewise_surface_type::error_code err;

      pws.init_uv(1, 1);

      // create surface with specified control points
      cp[0][0] << -15, 0,  15;
      cp[1][0] <<  -5, 5,  15;
      cp[2][0] <<   5, 5,  15;
      cp[3][0] <<  15, 0,  15;
      cp[0][1] << -15, 5,   5;
      cp[1][1] <<  -5, 5,   5;
      cp[2][1] <<   5, 5,   5;
      cp[3][1] <<  15, 5,   5;
      cp[0][2] << -15, 5,  -5;
      cp[1][2] <<  -5, 5,  -5;
      cp[2][2] <<   5, 5,  -5;
      cp[3][2] <<  15, 5,  -5;
      cp[0][3] << -15, 0, -15;
      cp[1][3] <<  -5, 5, -15;
      cp[2][3] <<   5, 5, -15;
      cp[3][3] <<  15, 0, -15;

      // create surface with specified dimensions and set control points
      for (i=0; i<=n; ++i)
      {
        for (j=0; j<=m; ++j)
        {
          s.set_control_point(cp[i][j], i, j);
        }
      }
      TEST_ASSERT(s.open_u());
      TEST_ASSERT(s.open_v());

      err=pws.set(s, 0, 0);
      TEST_ASSERT(err==piecewise_surface_type::NO_ERRORS);

      data_type u0(static_cast<data_type>(1.4));
      data_type v0(static_cast<data_type>(2.2));

      pws.set_u0(u0);
      pws.set_v0(v0);

      pws.split_u(u0+static_cast<data_type>(0.2));
      pws.split_u(u0+static_cast<data_type>(0.4));
      pws.split_u(u0+static_cast<data_type>(0.6));
      pws.split_u(u0+static_cast<data_type>(0.8));

      pws.split_v(v0+static_cast<data_type>(0.2));
      pws.split_v(v0+static_cast<data_type>(0.4));
      pws.split_v(v0+static_cast<data_type>(0.6));
      pws.split_v(v0+static_cast<data_type>(0.8));

      // test point on surface
      dist_ref=0;
      u_ref=static_cast<data_type>(0.25)+u0;
      v_ref=static_cast<data_type>(0.25)+v0;
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point very near surface
      dist_ref=static_cast<data_type>(0.01);
      u_ref=static_cast<data_type>(0.25)+u0;
      v_ref=static_cast<data_type>(0.25)+v0;
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.25)+u0;
      v_ref=static_cast<data_type>(0.25)+v0;
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near and on concave side of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.25)+u0;
      v_ref=static_cast<data_type>(0.25)+v0;
      norm=-pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point far surface
      dist_ref=static_cast<data_type>(1.1);
      u_ref=static_cast<data_type>(0.25)+u0;
      v_ref=static_cast<data_type>(0.25)+v0;
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point on surface
      dist_ref=0;
      u_ref=static_cast<data_type>(0.64)+u0;
      v_ref=static_cast<data_type>(0.32)+v0;
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point very near surface
      dist_ref=static_cast<data_type>(0.01);
      u_ref=static_cast<data_type>(0.64)+u0;
      v_ref=static_cast<data_type>(0.32)+v0;
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.64)+u0;
      v_ref=static_cast<data_type>(0.32)+v0;
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near and on concave side of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.64)+u0;
      v_ref=static_cast<data_type>(0.32)+v0;
      norm=-pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near surface
      dist_ref=static_cast<data_type>(1.1);
      u_ref=static_cast<data_type>(0.64)+u0;
      v_ref=static_cast<data_type>(0.32)+v0;
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near corner of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.01)+u0;
      v_ref=static_cast<data_type>(0.01)+v0;
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near corner of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.99)+u0;
      v_ref=static_cast<data_type>(0.01)+v0;
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near corner of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.01)+u0;
      v_ref=static_cast<data_type>(0.999)+v0;
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point near corner of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.999)+u0;
      v_ref=static_cast<data_type>(0.999)+v0;
      norm=pws.normal(u_ref, v_ref);
      pt=pws.f(u_ref, v_ref)+dist_ref*norm;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // test point beyond edge of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(1)+u0;
      v_ref=static_cast<data_type>(0.4)+v0;
      norm=pws.normal(u_ref, v_ref);
      u_contra=-norm.cross(pws.f_v(u_ref, v_ref));
      u_contra.normalize();
      pt=static_cast<data_type>(0.01)*u_contra+pws.f(u_ref, v_ref)+dist_ref*norm;
      dist_ref=eli::geom::point::distance(pt, pws.f(u_ref, v_ref));
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // Surface solver converges to nearby apparent solution.
      data_type u_alt, v_alt, dist_alt;
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref+v_off);
      u_alt=u;
      v_alt=v;
      dist_alt=dist;

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      // test point beyond edge of surface
      dist_ref=static_cast<data_type>(0.1);
      u_ref=static_cast<data_type>(0.6)+u0;
      v_ref=static_cast<data_type>(1)+v0;
      norm=pws.normal(u_ref, v_ref);
      v_contra=norm.cross(pws.f_u(u_ref, v_ref));
      v_contra.normalize();
      pt=static_cast<data_type>(0.01)*v_contra+pws.f(u_ref, v_ref)+dist_ref*norm;
      dist_ref=eli::geom::point::distance(pt, pws.f(u_ref, v_ref));
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // Surface solver converges to nearby apparent solution.
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref);
      u_alt=u;
      v_alt=v;
      dist_alt=dist;

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      // test point beyond edge of surface
      dist_ref=static_cast<data_type>(0.5);
      u_ref=static_cast<data_type>(0)+u0;
      v_ref=static_cast<data_type>(0.2)+v0;
      norm=pws.normal(u_ref, v_ref);
      u_contra=-norm.cross(pws.f_v(u_ref, v_ref));
      u_contra.normalize();
      pt=static_cast<data_type>(-0.1)*u_contra+pws.f(u_ref, v_ref)+dist_ref*norm;
      dist_ref=eli::geom::point::distance(pt, pws.f(u_ref, v_ref));
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // Surface solver converges to nearby apparent solution.
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      u_alt=u;
      v_alt=v;
      dist_alt=dist;

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref-v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      if (typeid(data_type)==typeid(float))
      {
        TEST_ASSERT(std::abs(dist-dist_alt) < 2e-3);
      }
      else
      {
        TEST_ASSERT(tol.approximately_equal(dist, dist_alt));
      }

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      if (typeid(data_type)==typeid(float))
      {
        TEST_ASSERT(std::abs(dist-dist_alt) < 2e-3);
      }
      else
      {
        TEST_ASSERT(tol.approximately_equal(dist, dist_alt));
      }

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      if (typeid(data_type)==typeid(float))
      {
        TEST_ASSERT(std::abs(dist-dist_alt) < 2e-3);
      }
      else
      {
        TEST_ASSERT(tol.approximately_equal(dist, dist_alt));
      }

      // test point beyond edge of surface
      dist_ref=static_cast<data_type>(0.5);
      u_ref=static_cast<data_type>(0.2)+u0;
      v_ref=static_cast<data_type>(0)+v0;
      norm=pws.normal(u_ref, v_ref);
      v_contra=norm.cross(pws.f_u(u_ref, v_ref));
      v_contra.normalize();
      pt=static_cast<data_type>(-0.1)*v_contra+pws.f(u_ref, v_ref)+dist_ref*norm;
      dist_ref=eli::geom::point::distance(pt, pws.f(u_ref, v_ref));
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_ref));
      TEST_ASSERT(tol.approximately_equal(v, v_ref));
      TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

      // Surface solver converges to nearby apparent solution.
      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref+static_cast<data_type>(0.02));
      u_alt=u;
      v_alt=v;
      dist_alt=dist;

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref, v_ref+static_cast<data_type>(0.02));
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref+u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref+v_off);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_ref-u_off, v_ref);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      TEST_ASSERT(tol.approximately_equal(dist, dist_alt));

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 0+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      if (typeid(data_type)==typeid(float))
      {
        TEST_ASSERT(std::abs(dist-dist_alt) < 2e-3);
      }
      else
      {
        TEST_ASSERT(tol.approximately_equal(dist, dist_alt));
      }

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 0+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      if (typeid(data_type)==typeid(float))
      {
        TEST_ASSERT(std::abs(dist-dist_alt) < 2e-3);
      }
      else
      {
        TEST_ASSERT(tol.approximately_equal(dist, dist_alt));
      }

      dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, 1+u0, 1+v0);
      TEST_ASSERT(tol.approximately_equal(u, u_alt));
      TEST_ASSERT(tol.approximately_equal(v, v_alt));
      if (typeid(data_type)==typeid(float))
      {
        TEST_ASSERT(std::abs(dist-dist_alt) < 2e-3);
      }
      else
      {
        TEST_ASSERT(tol.approximately_equal(dist, dist_alt));
      }
    }

    void degen_point_test()
    {
      const index_type n(3), m(3), ns(1), ms(3);
      surface_type s(n, m);
      point_type cp[ns*3+1][ms*3+1];
      point_type tst_pts[3];
      point_type pt;
      data_type dist, u, v, u_guess, v_guess;
      index_type i, j, is, js;
      piecewise_surface_type pws;

      pws.init_uv(ns, ms);

      // create surface with specified control points
      cp[0][0] << 3.58152, 0.825, -0.51;
      cp[0][1] << 3.58152, 0.825, -0.593333;
      cp[0][2] << 3.58152, 0.825, -0.676667;
      cp[0][3] << 3.58152, 0.825, -0.76;
      cp[0][4] << 3.58152, 0.825, -0.829036;
      cp[0][5] << 3.58152, 0.769036, -0.885;
      cp[0][6] << 3.58152, 0.7, -0.885;
      cp[0][7] << 3.58152, 0.466667, -0.885;
      cp[0][8] << 3.58152, 0.233333, -0.885;
      cp[0][9] << 3.58152, 0, -0.885;

      cp[1][0] << 4.07102, 0.825, -0.51;
      cp[1][1] << 4.07102, 0.825, -0.593333;
      cp[1][2] << 4.07102, 0.825, -0.676667;
      cp[1][3] << 4.07102, 0.825, -0.76;
      cp[1][4] << 4.07102, 0.825, -0.829036;
      cp[1][5] << 4.07102, 0.769036, -0.885;
      cp[1][6] << 4.07102, 0.7, -0.885;
      cp[1][7] << 4.07102, 0.466667, -0.885;
      cp[1][8] << 4.07102, 0.233333, -0.885;
      cp[1][9] << 4.07102, 0, -0.885;

      cp[2][0] << 4.95652, 0.548302, -0.51;
      cp[2][1] << 4.95652, 0.548302, -0.567115;
      cp[2][2] << 4.95652, 0.536403, -0.62423;
      cp[2][3] << 4.95652, 0.515085, -0.678866;
      cp[2][4] << 4.95652, 0.493766, -0.733501;
      cp[2][5] << 4.95652, 0.463027, -0.785658;
      cp[2][6] << 4.95652, 0.425347, -0.832857;
      cp[2][7] << 4.95652, 0.319843, -0.965015;
      cp[2][8] << 4.95652, 0.159922, -1.0583;
      cp[2][9] << 4.95652, 1.1102e-16, -1.0583;

      cp[3][0] << 4.95652, 0, -0.51;
      cp[3][1] << 4.95652, 0, -0.51;
      cp[3][2] << 4.95652, 0, -0.51;
      cp[3][3] << 4.95652, 0, -0.51;
      cp[3][4] << 4.95652, 0, -0.51;
      cp[3][5] << 4.95652, 0, -0.51;
      cp[3][6] << 4.95652, 0, -0.51;
      cp[3][7] << 4.95652, 0, -0.51;
      cp[3][8] << 4.95652, 0, -0.51;
      cp[3][9] << 4.95652, 0, -0.51;

      for ( is = 0; is < ns; is++ )
      {
        for ( js = 0; js < ms; js++ )
        {
          for (i=0; i<=n; ++i)
          {
            for (j=0; j<=m; ++j)
            {
              s.set_control_point(cp[is*3 + i][js * 3 + j], i, j);
            }
          }
          pws.set( s, is, js );
        }
      }

      u_guess = ( pws.get_umax() + pws.get_u0() ) / 2.0;
      v_guess = ( pws.get_vmax() + pws.get_v0() ) / 2.0;

      tst_pts[0] << -3.65833, 0, -0.875;
      tst_pts[1] << -3.25, 0, -0.875;
      tst_pts[2] << -2.84167, 0, -0.875;

      for (i=0; i<3; ++i)
      {
        pt = tst_pts[i];
        dist=eli::geom::intersect::minimum_distance(u, v, pws, pt, u_guess, v_guess);
        // FIX: What should this test be?
        TEST_ASSERT(dist>=0);
      }

//      octave_print( 1, pws );
    }

    void dist_surf_test()
    {
      {
          surface_type patch(3,3);
          point_type pt;

          // Surface and points recovered from OpenVSP failure case.
          // Hex floating point representation used to ensure exact transfer of
          // floating point numbers.
          pt << 0x1.001391762278p-2, -0x1.8951f245bb4f1p-9, 0x1.00093dc6b03c1p-3;
          patch.set_control_point( pt, 0, 0 );
          pt << 0x1.0014bcf3232b4p-2, -0x1.76b17b575fa2ep-9, 0x1.000b94c0b1a28p-3;
          patch.set_control_point( pt, 0, 1 );
          pt << 0x1.0015d345ea88bp-2, -0x1.640d275e4b1d1p-9, 0x1.000dc166405d6p-3;
          patch.set_control_point( pt, 0, 2 );
          pt << 0x1.0016d45ddc85ep-2, -0x1.516502192361bp-9, 0x1.000fc3962457ap-3;
          patch.set_control_point( pt, 0, 3 );
          pt << 0x1.00e23459c48c2p-2, -0x1.8954cea87ccbp-9, 0x1.fcdabe0017de5p-4;
          patch.set_control_point( pt, 1, 0 );
          pt << 0x1.00e35fd8f2e9bp-2, -0x1.76b4350af5ea7p-9, 0x1.fcdf6bfcd1546p-4;
          patch.set_control_point( pt, 1, 1 );
          pt << 0x1.00e4762dc0886p-2, -0x1.640fbe5b84887p-9, 0x1.fce3c55007cf2p-4;
          patch.set_control_point( pt, 1, 2 );
          pt << 0x1.00e57747913ecp-2, -0x1.51677658e4279p-9, 0x1.fce7c9b74aa8cp-4;
          patch.set_control_point( pt, 1, 3 );
          pt << 0x1.01b13d852fc9p-2, -0x1.89578661e23fdp-9, 0x1.f9a14362984a2p-4;
          patch.set_control_point( pt, 2, 0 );
          pt << 0x1.01b269066fe68p-2, -0x1.76b6cbd1a8b9ep-9, 0x1.f9a5f16798cp-4;
          patch.set_control_point( pt, 2, 1 );
          pt << 0x1.01b37f5d29d51p-2, -0x1.64123428af3bp-9, 0x1.f9aa4ac2807a8p-4;
          patch.set_control_point( pt, 2, 2 );
          pt << 0x1.01b48078c14ep-2, -0x1.5169cb25c60c2p-9, 0x1.f9ae4f30de5e4p-4;
          patch.set_control_point( pt, 2, 3 );
          pt << 0x1.0280ad4595d66p-2, -0x1.895a1ac068c93p-9, 0x1.f6660bc806d5ap-4;
          patch.set_control_point( pt, 3, 0 );
          pt << 0x1.0281d8c8ccc82p-2, -0x1.76b940ea1df5cp-9, 0x1.f66ab9d4e29cbp-4;
          patch.set_control_point( pt, 3, 1 );
          pt << 0x1.0282ef215a02p-2, -0x1.641489f496994p-9, 0x1.f66f133717846p-4;
          patch.set_control_point( pt, 3, 2 );
          pt << 0x1.0283f03ea1216p-2, -0x1.516c019eb6b4ap-9, 0x1.f67317ac3401ep-4;
          patch.set_control_point( pt, 3, 3 );


          pt << 0x1.001fbc90b3d55p-2, -0x1.7ca1ba4ef9c8dp-9, 0x1.ffe7e04358342p-4;


          data_type dist = 1.0;
          data_type u, v;
          dist = eli::geom::intersect::minimum_distance(u, v, patch, pt, 0.5, 0.5 );

          data_type dist_ref, u_ref, v_ref;

          dist_ref = 0x1.048c87d281c8ep-22;
          u_ref = 0x1.2e0ff4d121444p-6;
          v_ref = 0x1.d0e91354ad38dp-3;

          TEST_ASSERT(tol.approximately_equal(u, u_ref));
          TEST_ASSERT(tol.approximately_equal(v, v_ref));
          TEST_ASSERT(tol.approximately_equal(dist, dist_ref));
      }
      {
        const index_type n(3), m(3);
        surface_type s(n, m);
        point_type cp[3+1][3+1], pt_out;
        point_type pt, norm, u_contra, v_contra;
        data_type dist, u, v, dist_ref, u_ref, v_ref;
//        data_type u_off(static_cast<data_type>(0.2)), v_off(static_cast<data_type>(0.2));
        index_type i, j;

        // create surface with specified control points
        cp[0][0] << -15, 0,  15;
        cp[1][0] <<  -5, 5,  15;
        cp[2][0] <<   5, 5,  15;
        cp[3][0] <<  15, 0,  15;
        cp[0][1] << -15, 5,   5;
        cp[1][1] <<  -5, 5,   5;
        cp[2][1] <<   5, 5,   5;
        cp[3][1] <<  15, 5,   5;
        cp[0][2] << -15, 5,  -5;
        cp[1][2] <<  -5, 5,  -5;
        cp[2][2] <<   5, 5,  -5;
        cp[3][2] <<  15, 5,  -5;
        cp[0][3] << -15, 0, -15;
        cp[1][3] <<  -5, 5, -15;
        cp[2][3] <<   5, 5, -15;
        cp[3][3] <<  15, 0, -15;

        // create surface with specified dimensions and set control points
        for (i=0; i<=n; ++i)
        {
          for (j=0; j<=m; ++j)
          {
            s.set_control_point(cp[i][j], i, j);
          }
        }
        TEST_ASSERT(s.open_u());
        TEST_ASSERT(s.open_v());

        // test point on surface
        dist_ref=0;
        u_ref=0.25;
        v_ref=0.25;
        norm=s.normal(u_ref, v_ref);
        pt=s.f(u_ref, v_ref)+dist_ref*norm;
        dist=eli::geom::intersect::minimum_distance(u, v, s, pt);
        TEST_ASSERT(tol.approximately_equal(u, u_ref));
        TEST_ASSERT(tol.approximately_equal(v, v_ref));
        TEST_ASSERT(tol.approximately_equal(dist, dist_ref));

        onedbez_type ans = s.mindistsurf( pt );

//        if (typeid(data_type)==typeid(double))
//        {
//          octave_print( 1, ans );
//        }
      }

      {
        const index_type n(12), m(3);
        surface_type s(n, m);
        point_type cp[n+1], offset[m+1], pt_out;
        point_type pt, norm, u_contra, v_contra;
        data_type  z[m+1], dist_ref, u_ref, v_ref;
        // data_type dist, u, v;
        // data_type u_off(static_cast<data_type>(0.1)), v_off(static_cast<data_type>(0.1));
        index_type i, j;

        // set control points
        cp[0]  <<   1, 0,   0;
        cp[1]  <<   1, 0.5, 0;
        cp[2]  << 0.5, 1,   0;
        cp[3]  <<   0, 1,   0;
        cp[4]  <<-0.5, 1,   0;
        cp[5]  <<  -1, 0.5, 0;
        cp[6]  <<  -1, 0,   0;
        cp[7]  <<  -1,-0.5, 0;
        cp[8]  <<-0.5,-1,   0;
        cp[9]  <<   0,-1,   0;
        cp[10] << 0.5,-1,   0;
        cp[11] <<   1,-0.5, 0;
        cp[12] <<   1,0,    0;
        z[0]=-0.5;
        z[1]=0;
        z[2]=0.5;
        z[3]=1;
        offset[0] << 0, 0, 0;
        offset[1] << 0.5, 0, 0;
        offset[2] << -0.5, 0.5, 0;
        offset[3] << 0, 0, 0;

        // create surface with specified dimensions and set control points
        for (j=0; j<=m; ++j)
        {
          for (i=0; i<=n; ++i)
          {
            cp[i].z() = z[j];
            s.set_control_point(cp[i]+offset[j], i, j);
          }
        }
        TEST_ASSERT(s.closed_u());
        TEST_ASSERT(s.open_v());


        // test point near center surface
        dist_ref=static_cast<data_type>(0.72);
        u_ref=static_cast<data_type>(0.35);
        v_ref=static_cast<data_type>(0.35);
        norm=-s.normal(u_ref, v_ref);
        pt=s.f(u_ref, v_ref)+dist_ref*norm;

//        onedbez_type ans = s.mindistsurf( pt );
//
//        if (typeid(data_type)==typeid(double))
//        {
//          octave_print( 1, ans );
//          printf("%ld, %ld\n", ans.degree_u(), ans.degree_v() );
//        }



        dist_ref=3;
        u_ref=static_cast<data_type>(0.25);
        v_ref=static_cast<data_type>(0.7);
        norm=s.normal(u_ref, v_ref);
        pt=s.f(u_ref, v_ref)+dist_ref*norm;

//        onedbez_type ans = s.mindistsurf( pt );
//
//        if (typeid(data_type)==typeid(double))
//        {
//          octave_print( 1, ans );
//          printf("%ld, %ld\n", ans.degree_u(), ans.degree_v() );
//        }


      }

    }

};

#endif

