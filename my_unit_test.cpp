// #define BOOST_TEST_DYN_LINK
// #define BOOST_TEST_MAIN
#define BOOST_AUTO_TEST_MAIN

#include <iostream>
#include <boost/timer/timer.hpp>
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include <boost/test/auto_unit_test.hpp>

#include <cmath>

using  namespace  boost::timer;
using  namespace  Eigen;

int add(int i, int j) {return i+j;}

BOOST_AUTO_TEST_CASE( multiply_six_by_six )
{
    MatrixXd m1(6,6);
    m1 <<   5 ,9 ,1 ,4 ,4 ,6,
            8 ,2 ,5 ,1 ,8 ,0,
            7 ,4 ,6 ,2 ,5 ,2,
            3 ,8 ,0 ,1 ,4 ,5,
            8 ,4 ,1 ,1 ,6 ,6,
            3 ,6 ,7 ,0 ,7 ,9;
    MatrixXd m2(6,6);
    m2 <<   2 ,4 ,0 ,0 ,3 ,0,
            7 ,2 ,9 ,8 ,3 ,1,
            1 ,4 ,7 ,2 ,8 ,2,
            0 ,5 ,8 ,8 ,7 ,0,
            4 ,1 ,3 ,2 ,5 ,8,
            7 ,5 ,1 ,6 ,4 ,2;
    
    MatrixXd m3(6,6);
    m3 <<   132 ,96 ,138 ,150 ,122 ,55,
            67 ,69 ,85 ,50 ,117 ,76,
            82 ,85 ,111 ,82 ,128 ,60,
            113 ,62 ,97 ,110 ,80 ,50,
            111 ,85 ,75 ,90 ,105 ,66,
            146 ,104 ,133 ,130 ,154 ,94;
    

    BOOST_CHECK( m1 * m2 == m3 );
}

BOOST_AUTO_TEST_CASE( multiply_fifteen_by_fifteen)
{
        MatrixXd m1(15,15);
        m1 <<   5 ,9 ,7 ,3 ,5 ,2 ,4 ,8 ,5 ,1 ,6 ,2 ,9 ,5 ,8,
                3 ,0 ,0 ,7 ,8 ,6 ,5 ,7 ,4 ,7 ,8 ,7 ,7 ,5 ,5,
                0 ,1 ,3 ,3 ,8 ,3 ,8 ,5 ,6 ,0 ,8 ,2 ,0 ,6 ,0,
                0 ,7 ,9 ,8 ,9 ,3 ,5 ,7 ,5 ,7 ,4 ,1 ,8 ,2 ,7,
                2 ,7 ,0 ,6 ,7 ,5 ,1 ,9 ,2 ,0 ,3 ,4 ,2 ,2 ,0,
                4 ,2 ,3 ,3 ,9 ,5 ,5 ,3 ,0 ,0 ,7 ,5 ,8 ,4 ,3,
                6 ,3 ,4 ,7 ,8 ,8 ,1 ,2 ,2 ,4 ,5 ,5 ,5 ,8 ,1,
                2 ,2 ,8 ,3 ,5 ,5 ,4 ,0 ,3 ,0 ,7 ,4 ,0 ,3 ,1,
                1 ,9 ,3 ,5 ,2 ,8 ,8 ,8 ,2 ,7 ,6 ,6 ,7 ,5 ,0,
                3 ,1 ,1 ,9 ,5 ,9 ,7 ,2 ,2 ,6 ,0 ,5 ,2 ,1 ,7,
                4 ,4 ,4 ,6 ,8 ,0 ,6 ,8 ,2 ,3 ,0 ,4 ,0 ,4 ,3,
                6 ,6 ,8 ,9 ,0 ,4 ,2 ,4 ,0 ,6 ,2 ,9 ,8 ,3 ,1,
                1 ,5 ,8 ,7 ,2 ,8 ,0 ,1 ,0 ,9 ,9 ,1 ,2 ,8 ,3,
                6 ,7 ,9 ,0 ,3 ,3 ,0 ,1 ,1 ,5 ,7 ,6 ,6 ,8 ,3,
                1 ,6 ,5 ,8 ,6 ,5 ,6 ,4 ,3 ,9 ,0 ,3 ,4 ,9 ,8;

        MatrixXd m2(15,15);
        m2 <<   6 ,4 ,5 ,0 ,8 ,7 ,7 ,9 ,7 ,8 ,8 ,5 ,7 ,5 ,4,
                8 ,5 ,7 ,7 ,5 ,1 ,3 ,7 ,6 ,8 ,1 ,3 ,7 ,4 ,5,
                4 ,1 ,0 ,4 ,3 ,8 ,3 ,4 ,8 ,2 ,2 ,9 ,9 ,8 ,2,
                2 ,9 ,6 ,2 ,1 ,4 ,4 ,4 ,9 ,0 ,9 ,8 ,4 ,8 ,4,
                7 ,2 ,0 ,5 ,8 ,8 ,9 ,3 ,2 ,2 ,1 ,0 ,8 ,4 ,3,
                9 ,7 ,6 ,9 ,3 ,7 ,6 ,6 ,1 ,6 ,2 ,9 ,5 ,3 ,6,
                3 ,1 ,9 ,7 ,7 ,8 ,1 ,6 ,3 ,4 ,1 ,2 ,0 ,5 ,1,
                8 ,6 ,8 ,9 ,4 ,8 ,0 ,5 ,5 ,0 ,4 ,6 ,0 ,6 ,3,
                3 ,1 ,7 ,5 ,4 ,4 ,5 ,4 ,7 ,3 ,7 ,0 ,5 ,8 ,8,
                0 ,7 ,2 ,5 ,9 ,7 ,0 ,1 ,1 ,5 ,4 ,4 ,8 ,6 ,6,
                7 ,7 ,8 ,6 ,9 ,4 ,6 ,5 ,2 ,1 ,8 ,8 ,9 ,8 ,7,
                5 ,7 ,1 ,3 ,0 ,0 ,0 ,3 ,9 ,3 ,2 ,5 ,0 ,4 ,9,
                7 ,6 ,7 ,7 ,0 ,7 ,6 ,7 ,2 ,4 ,3 ,0 ,4 ,2 ,6,
                6 ,8 ,6 ,4 ,3 ,9 ,2 ,6 ,3 ,8 ,8 ,8 ,1 ,9 ,3,
                2 ,5 ,0 ,7 ,5 ,8 ,3 ,3 ,2 ,5 ,6 ,6 ,6 ,6 ,9;

        MatrixXd m3(15,15);
        m3 <<   441 ,377 ,398 ,451 ,353 ,485 ,305 ,413 ,351 ,312 ,341 ,363 ,399 ,448 ,393,
                405 ,445 ,386 ,434 ,367 ,482 ,297 ,358 ,309 ,265 ,365 ,374 ,354 ,443 ,421,
                293 ,234 ,299 ,301 ,280 ,336 ,212 ,252 ,219 ,160 ,234 ,249 ,233 ,337 ,228,
                399 ,390 ,366 ,471 ,374 ,515 ,306 ,366 ,352 ,270 ,324 ,368 ,442 ,470 ,392,
                322 ,280 ,274 ,291 ,212 ,268 ,197 ,254 ,243 ,165 ,199 ,240 ,215 ,266 ,237,
                365 ,311 ,292 ,334 ,278 ,381 ,278 ,315 ,237 ,223 ,243 ,281 ,295 ,316 ,296,
                388 ,390 ,316 ,337 ,303 ,420 ,301 ,345 ,301 ,283 ,320 ,368 ,352 ,391 ,337,
                256 ,211 ,207 ,238 ,225 ,274 ,201 ,225 ,226 ,161 ,195 ,271 ,264 ,290 ,222,
                431 ,430 ,443 ,463 ,335 ,435 ,235 ,388 ,322 ,303 ,289 ,381 ,326 ,414 ,372,
                266 ,325 ,260 ,324 ,265 ,370 ,214 ,265 ,252 ,228 ,250 ,305 ,267 ,320 ,312,
                278 ,262 ,250 ,284 ,270 ,353 ,181 ,260 ,283 ,192 ,228 ,258 ,236 ,330 ,231,
                343 ,393 ,311 ,322 ,239 ,365 ,215 ,340 ,371 ,264 ,289 ,371 ,319 ,373 ,341,
                322 ,390 ,291 ,341 ,309 ,393 ,231 ,291 ,251 ,260 ,312 ,421 ,385 ,407 ,319,
                362 ,343 ,274 ,321 ,298 ,379 ,243 ,332 ,292 ,302 ,281 ,353 ,369 ,377 ,335,
                349 ,411 ,335 ,420 ,342 ,496 ,243 ,343 ,318 ,323 ,329 ,384 ,359 ,453 ,370;

        BOOST_CHECK(m1 * m2 == m3);
}

BOOST_AUTO_TEST_CASE( multiply_fifty_by_fifty ) 
{

}