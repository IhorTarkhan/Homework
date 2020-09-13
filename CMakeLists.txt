# Standard CMake configuration
cmake_minimum_required(VERSION 3.15)
project(Homework)
set(CMAKE_CXX_STANDARD 14)

# Included dependent subprojects (using main_Lab_<Semester>_<Laboratory>() function)
add_executable(Homework MAIN.cpp)

# Independent subprojects (with their main.cpp and CMakeLists.txt)
add_subdirectory(3rdSemester/LaboratoryWork1)

# Google tests include
add_subdirectory(lib/googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(Google_Tests_run gtest gtest_main)
