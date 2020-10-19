#define BOOST_TEST_MODULE decorator_11
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <iostream>
#include <boost/timer/timer.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/test/included/unit_test.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <Eigen/Dense>
#include <cmath>

using  namespace  boost::timer;
using namespace Eigen;
namespace utf = boost::unit_test;
using namespace boost::numeric::ublas;

void addition_performance() {

    for (int i = 10; i < 10000; i += 1000) {
        MatrixXd Eigen_matrix_1 = MatrixXd::Random(i,i);
        MatrixXd Eigen_matrix_2 = MatrixXd::Random(i,i);

        matrix<double> uBlas_matrix_1(i,i);
        matrix<double> uBlas_matrix_2(i,i);

        for (int m = 0; m < i; m ++) {
            for (int n = 0; n < i; n ++) {
                uBlas_matrix_1(m,n) = Eigen_matrix_1(m,n);
                uBlas_matrix_2(m,n) = Eigen_matrix_2(m,n);
            }
        }


        cpu_timer* timer = new cpu_timer;

        // matrix_1 += matrix_2;
        uBlas_matrix_1 += uBlas_matrix_2;

        std::cout << "The operation of an addition of two " << i << "x" << i << "matrices took: " << timer->format() << std::endl;

        delete timer;
    }
}

void multiplication_matrix_matrix_performance() {

    for (int i = 10; i < 10000; i += 1000) {
        MatrixXd matrix_1 = MatrixXd::Random(i,i);
        MatrixXd matrix_2 = MatrixXd::Random(i,i);
        cpu_timer* timer = new cpu_timer;

        matrix_1 *= matrix_2;

        std::cout << "The operation of a product of two " << i << "x" << i << "matrices took: " << timer->format() << std::endl;

        delete timer;
    }

}

void multiplication_matrix_vector_performance() {
    
    for (int i = 10; i < 10000; i++) {
        MatrixXd matrix_1 = MatrixXd::Random(i,i);
        VectorXd vector_1 = VectorXd::Random(i,1);
        cpu_timer* timer = new cpu_timer;

        matrix_1 *= vector_1;

        std::cout << "The operation of a product of a " << i << "x" << i << "matrix and a " << i << " length vector took: " << timer->format() << std::endl;
    }
}


BOOST_AUTO_TEST_CASE(addition_performance_test, * utf::timeout(1200))
{
    #ifdef BOOST_SIGACTION_BASED_SIGNAL_HANDLING
    std::cout << "\n\n\n\n\n\n\n\nStarting addition peformance test" << std::endl;
    addition_performance();
    BOOST_TEST(true);
    #else
    BOOST_TEST(false);
    #endif
}

BOOST_AUTO_TEST_CASE(multiplication_matrix_matrix_performance_test, * utf::timeout(1200))
{
    #ifdef BOOST_SIGACTION_BASED_SIGNAL_HANDLING
    std::cout << "\n\n\n\n\n\n\n\nStarting multiplication peformance test" << std::endl;
    multiplication_matrix_matrix_performance();
    BOOST_TEST(true);
    #else
    BOOST_TEST(false);
    #endif
}

BOOST_AUTO_TEST_CASE(multiplication_matrix_vector_performance_test, * utf::timeout(1200))
{
    #ifdef BOOST_SIGACTION_BASED_SIGNAL_HANDLING
    std::cout << "\n\n\n\n\n\n\n\nStarting multiplication by vector peformance test" << std::endl;
    multiplication_matrix_vector_performance();
    BOOST_TEST(true);
    #else
    BOOST_TEST(false);
    #endif
}