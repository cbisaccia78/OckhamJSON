cmake_minimum_required(VERSION 3.2)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY"

project(OckhamJSON C)

enable_testing()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Werroe=strict-prototypes")

add_subdirectory(OckhamJSON)
add_subdirectory(Tests)
add_subdirectory(Examples)
