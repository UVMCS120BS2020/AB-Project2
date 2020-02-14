cmake_minimum_required(VERSION 3.15)
project(AB_Project2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=return-type")

add_executable(AB_Project2 main.cpp Piano.cpp Piano.h GlobalFunctions.cpp GlobalFunctions.h)
add_executable(Testing testing.cpp Piano.cpp Piano.h GlobalFunctions.cpp GlobalFunctions.h)