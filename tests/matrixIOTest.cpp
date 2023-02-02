#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

using namespace Eigen;

struct matrixIOFixture {
  matrixIOFixture()
  {
    A = MatrixXd(3, 3);
    expectedA = MatrixXd(3, 3);
    expectedA << -1.0,  2.0, -3.0,
				  1.5, -2.5,  3.5,
				 -2.0,  3.0, -4.0;
  }

  MatrixXd expectedA;
  MatrixXd A;
};

BOOST_FIXTURE_TEST_SUITE(matrixIOTests, matrixIOFixture, *boost::unit_test::tolerance(1e-12))

BOOST_AUTO_TEST_CASE(openData)
{
  A = matrixIO::openData("matrixIOTestData.csv", 3);

  BOOST_TEST(A(0) == expectedA(0));
  BOOST_TEST(A(1) == expectedA(1));
  BOOST_TEST(A(2) == expectedA(2));
  BOOST_TEST(A(3) == expectedA(3));
  BOOST_TEST(A(4) == expectedA(4));
  BOOST_TEST(A(5) == expectedA(5));
  BOOST_TEST(A(6) == expectedA(6));
  BOOST_TEST(A(7) == expectedA(7));
  BOOST_TEST(A(8) == expectedA(8));
}

BOOST_AUTO_TEST_SUITE_END()
