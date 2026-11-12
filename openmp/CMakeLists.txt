cmake_minimum_required(VERSION 3.19)
project(my_openmp_project CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenMP REQUIRED)

add_executable(my_openmp_program src/main.cpp)
target_link_libraries(my_openmp_program PRIVATE OpenMP::OpenMP_CXX)