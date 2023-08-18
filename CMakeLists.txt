cmake_minimum_required(VERSION 3.26)
project(test)

set(CMAKE_CXX_STANDARD 20)

add_executable(test main.cpp)
add_executable(test01 sly_test/test01.cc)
add_executable(sharePtr sly_test/sharePtr.h sly_test/sharePtr.cc)
add_executable(Singleton sly_test/Singleton.h sly_test/Singleton.cc)
add_executable(cin_cout sly_test/cin_cout.cc)
add_executable(const sly_test/const.cc)
