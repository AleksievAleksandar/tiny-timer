cmake_minimum_required(VERSION 3.16)
project(timer VERSION 0.1.0 LANGUAGES CXX)

add_subdirectory(src/tiny_timer)

add_executable(timer src/main.cpp)
target_compile_options(timer PUBLIC -Wall -Wextra -pedantic -Werror)
target_link_libraries(timer PUBLIC libtiny_timer)
