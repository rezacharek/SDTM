cmake_minimum_required(VERSION 3.8)
project(EigenTest)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-O3 -msse2 -Wall -Wextra")
# set(CMAKE_CXX_FLAGS "-x ssse3 -Wall -Wextra")

find_package (Eigen3 3.3 REQUIRED)
find_package(Boost COMPONENTS system filesystem unit_test_framework timer REQUIRED)


ADD_EXECUTABLE(performance performance.cpp)
ADD_EXECUTABLE(my_unit_test  my_unit_test.cpp)
ADD_EXECUTABLE(performance_ublas performance_ublas.cpp)
target_link_libraries(performance
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      ${Boost_TIMER_LIBRARY}
                      )
target_link_libraries (performance Eigen3::Eigen)

target_link_libraries(my_unit_test
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      ${Boost_TIMER_LIBRARY}
                      )
target_link_libraries(my_unit_test Eigen3::Eigen)

target_link_libraries(performance_ublas 
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      ${Boost_TIMER_LIBRARY}
                      )
target_link_libraries(performance_ublas  Eigen3::Eigen)
