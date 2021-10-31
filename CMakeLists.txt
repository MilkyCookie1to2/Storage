cmake_minimum_required(VERSION 3.20)
project(LB_MG_3S_4)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(LB_MG_3S_4 main.cpp "class .h" SH.cpp classes/date.cpp classes/datauser.cpp classes/driver.cpp classes/tenant.cpp classes/security.cpp classes/loader.cpp classes/product.cpp stuff.cpp boxes.cpp)
