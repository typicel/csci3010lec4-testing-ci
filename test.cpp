#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>

TEST_CASE("Testing if the sum of the vector is calculated correctly", "[sum]"){

  SECTION("Simple vector of 3 values") {
    std::vector<double> v{1.0, 2.0, 3.0};
    REQUIRE( v.size() == 3 );
    REQUIRE( Sum(v) == 6.0 );
  }

  SECTION("Vector of all 0s") {
    std::vector<double> v1(10);
    REQUIRE( v1.size() == 10);
    REQUIRE( Sum(v1) == 0.0 );
  }
}

TEST_CASE("Testing if adding a number to a vector is calculated correctly", "[addn]") {
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  SECTION("Testing with positive values of n") {
    int n = 3;

    std::vector<int> res = AddN(v, n);

    REQUIRE(v.size() == res.size());
    REQUIRE( res[0] == 4 );
    REQUIRE( res[res.size()-1] == 13 );
    int random = rand() % res.size();
    REQUIRE( res[random] == v[random] + n );

  }

  SECTION("Testing with negative values of n") {
    int n = -3;

    std::vector<int> res = AddN(v, n);

    REQUIRE(v.size() == res.size());
    REQUIRE( res[0] == -2 );
    REQUIRE( res[res.size()-1] == 7 );
    int random = rand() % res.size();
    REQUIRE( res[random] == v[random] + n );
  }

  SECTION("n = 0") {
    int n = 0;
    std::vector<int> res = AddN(v, n);

    REQUIRE( v.size() == res.size() );
    REQUIRE( v == res );
  }
}

TEST_CASE("Testing that Sign() returns the right value", "[sign]") {
  REQUIRE( Sign(10) == 1 );
  REQUIRE( Sign(-10) == -1 );
  REQUIRE( Sign(0) == 1 );
}

TEST_CASE("Testing that Factorial() returns the right value", "[factorial"){

  SECTION("Base cases"){
    REQUIRE( Factorial(0) == 1 );
    REQUIRE( Factorial(1) == 1 );
  }

  SECTION("Normal cases") {
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
  }

}
