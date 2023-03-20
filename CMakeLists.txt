cmake_minimum_required(VERSION 3.26)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

project( OckhamJSON VERSION 0.0.0.0 DESCRIPTION "Parser/Generator of RFC JSON in C" HOMEPAGE_URL "https://gitlab.com/utilities6655811/OckhamJSON" LANGUAGES C)
configure_file(JSON.h.in JSON.h)

add_executable(unittests MACOSX_BUNDLE unittests.c)
target_include_directories(unittests PUBLIC "${PROJECT_BINARY_DIR}")
enable_testing()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Werror=strict-prototypes")

#add_subdirectory(Tests)
#add_subdirectory(Examples)

