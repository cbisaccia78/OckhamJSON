cmake_minimum_required(VERSION 3.26)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

project( OckhamJSON VERSION 0.0.0.0 DESCRIPTION "Parser/Generator of RFC JSON in C" HOMEPAGE_URL "https://gitlab.com/StringUtilities6655811/OckhamJSON" LANGUAGES C)

configure_file(JSON.h.in JSON.h)


add_executable(unittests MACOSX_BUNDLE unittests.c)

target_include_directories(unittests PUBLIC 
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/StringUtilities")

add_library(json JSON.c)
add_subdirectory(StringUtilities)
add_subdirectory(Tests)
target_link_libraries(unittests PUBLIC stringutils)

include(CTest)
enable_testing()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Werror=strict-prototypes")

#add_subdirectory(Examples)

