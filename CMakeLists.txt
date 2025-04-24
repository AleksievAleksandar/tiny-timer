cmake_minimum_required(VERSION 3.16)
project(timer VERSION 0.1.0 LANGUAGES CXX)

add_executable(timer src/main.cpp)
target_compile_options(timer PUBLIC -Wall -Wextra -pedantic -Werror)
