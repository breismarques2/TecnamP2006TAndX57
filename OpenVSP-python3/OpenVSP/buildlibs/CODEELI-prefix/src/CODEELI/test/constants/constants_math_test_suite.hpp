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

#ifndef constants_math_test_suite_hpp
#define constants_math_test_suite_hpp

#include <cmath>    // std::pow, std::exp

#include <typeinfo> // typeid
#include <string>   // std::string
#include <sstream>  // std::stringstream
#include <iomanip>  // std::setw
#include <vector>   // std::vector

#include <cmath> // std::tan and others

#include "eli/constants/math.hpp"

template<typename T__>
void set_pi(T__ &p)
{
  p=3.14;
}
template<>
void set_pi<float>(float &p)
{
  p=3.141592653589793238462643383279502884196716939937510582f;
}
template<>
void set_pi<double>(double &p)
{
  p=3.141592653589793238462643383279502884196716939937510582;
}
template<>
void set_pi<long double>(long double &p)
{
  p=3.141592653589793238462643383279502884196716939937510582L;
}

template<typename data__>
class constants_math_test_suite : public Test::Suite
{
  protected:
    void AddTests(const float &)
    {
      TEST_ADD(constants_math_test_suite<float>::exp_test);
      TEST_ADD(constants_math_test_suite<float>::pi_test);
      TEST_ADD(constants_math_test_suite<float>::sqrt_test);
    }

    void AddTests(const double &)
    {
      TEST_ADD(constants_math_test_suite<double>::exp_test);
      TEST_ADD(constants_math_test_suite<double>::pi_test);
      TEST_ADD(constants_math_test_suite<double>::sqrt_test);
    }

    void AddTests(const long double &)
    {
      TEST_ADD(constants_math_test_suite<long double>::exp_test);
      TEST_ADD(constants_math_test_suite<long double>::pi_test);
      TEST_ADD(constants_math_test_suite<long double>::sqrt_test);
    }

  public:
    constants_math_test_suite()
    {
      // add the tests
      AddTests(data__());
    }
    ~constants_math_test_suite()
    {
    }

  private:
    void exp_test()
    {
      data__ ans, one(1), two(2);

      // test exp(1)
      ans=std::exp(one);
      TEST_ASSERT(ans==eli::constants::math<data__>::exp());

      // test ln(2)
      ans=std::log(two);
      TEST_ASSERT(ans==eli::constants::math<data__>::ln_two());

      // test log(exp(1))
      ans=std::log10(std::exp(one));
      TEST_ASSERT(ans==eli::constants::math<data__>::log_exp());
    }

    void pi_test()
    {
      data__ ans, one(1), two(2), four(4), pi;

      // set reference value for pi
      set_pi(pi);

      // test pi
      ans=pi;
      TEST_ASSERT(ans==eli::constants::math<data__>::pi());

      // test 2*pi
      ans=two*pi;
      TEST_ASSERT(ans==eli::constants::math<data__>::two_pi());

      // test pi/2
      ans=pi/two;
      TEST_ASSERT(ans==eli::constants::math<data__>::pi_by_two());

      // test pi/4
      ans=pi/four;
      TEST_ASSERT(ans==eli::constants::math<data__>::pi_by_four());

      // test pi*pi
      ans=pi*pi;
      TEST_ASSERT(ans==eli::constants::math<data__>::pi_squared());

      // test pi*pi*pi
      ans=pi*pi*pi;
      TEST_ASSERT(ans==eli::constants::math<data__>::pi_cubed());

      // test sqrt(pi)
      ans=std::sqrt(pi);
      TEST_ASSERT(ans==eli::constants::math<data__>::sqrt_pi());

      // test cbrt(pi)
      ans=std::cbrt(pi);
      TEST_ASSERT(ans==eli::constants::math<data__>::cbrt_pi());

      // test 1/pi
      ans=one/pi;
      TEST_ASSERT(ans==eli::constants::math<data__>::one_by_pi());

      // test 2/pi
      ans=two/pi;
      TEST_ASSERT(ans==eli::constants::math<data__>::two_by_pi());

      // test 1/sqrt(pi)
      ans=one/std::sqrt(pi);
      TEST_ASSERT(ans==eli::constants::math<data__>::one_by_sqrt_pi());

      // test 2/sqrt(pi)
      ans=two/std::sqrt(pi);
      TEST_ASSERT(ans==eli::constants::math<data__>::two_by_sqrt_pi());
    }

    void sqrt_test()
    {
      data__ ans, two(2);

      // test sqrt(2)
      ans=std::sqrt(two);
      TEST_ASSERT(ans==eli::constants::math<data__>::sqrt_two());

      // test sqrt(2)/2
      ans=std::sqrt(two)/two;
      TEST_ASSERT(ans==eli::constants::math<data__>::sqrt_two_by_two());
    }
};

#endif

