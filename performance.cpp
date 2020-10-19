#define BOOST_TEST_MODULE decorator_11
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <iostream>
#include <boost/timer/timer.hpp>
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include <boost/test/included/unit_test.hpp>

#include <cmath>

using  namespace  boost::timer;
using  namespace  Eigen;
namespace utf = boost::unit_test;


void addition_performance() {

    for (int i = 10; i < 10000; i += 1000) {
        MatrixXd matrix_1 = MatrixXd::Random(i,i);
        MatrixXd matrix_2 = MatrixXd::Random(i,i);
        cpu_timer* timer = new cpu_timer;

        matrix_1 += matrix_2;

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