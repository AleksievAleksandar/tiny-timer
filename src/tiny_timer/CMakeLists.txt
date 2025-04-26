add_library(libtiny_timer STATIC tiny_timer.cpp)
target_compile_options(libtiny_timer PRIVATE -Wall -Wextra -pedantic -Werror)
target_include_directories(libtiny_timer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
