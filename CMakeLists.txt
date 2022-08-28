project(algorithm)
cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

add_executable(mac_algorithm main.cpp)
include_directories(include)
add_subdirectory(leetcode_alg)
add_subdirectory(primary_alg)
add_subdirectory(backtrack)
add_subdirectory(dp)
add_subdirectory(sword_offer)
add_subdirectory(interview)