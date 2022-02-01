#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <vector>
#include "matrixIO.hpp"

using namespace std;
using namespace Eigen;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    expected_matrix = MatrixXd(3, 3);
    expected_matrix << 0.680375, 0.59688, -0.329554,
        -0.211234, 0.823295, 0.536459,
        0.566198, -0.604897, -0.444451;
  }
  MatrixXd expected_matrix;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(openData)
{
  MatrixXd X;
  X = matrixIO::openData("../data/m3.csv", 3);

  BOOST_TEST(X(0, 0) == expected_matrix(0, 0));
  BOOST_TEST(X(0, 1) == expected_matrix(0, 1));
  BOOST_TEST(X(0, 2) == expected_matrix(0, 2));
  BOOST_TEST(X(1, 0) == expected_matrix(1, 0));
  BOOST_TEST(X(1, 1) == expected_matrix(1, 1));
  BOOST_TEST(X(1, 2) == expected_matrix(1, 2));
  BOOST_TEST(X(2, 0) == expected_matrix(2, 0));
  BOOST_TEST(X(2, 1) == expected_matrix(2, 1));
  BOOST_TEST(X(2, 2) == expected_matrix(2, 2));
}

BOOST_AUTO_TEST_SUITE_END()

