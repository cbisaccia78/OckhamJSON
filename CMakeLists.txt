

cmake_minimum_required(VERSION 3.26)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

project( OckhamJSON VERSION 0.0.0.0 DESCRIPTION "Parser/Generator of RFC JSON in C" HOMEPAGE_URL "https://gitlab.com/StringUtilities6655811/OckhamJSON" LANGUAGES C)

include(CTest)

configure_file(JSON.h.in JSON.h)

add_executable(example MACOSX_BUNDLE example.c JSON.c)
                          


target_link_libraries(example PUBLIC stringutils jsonutils)
#target_include_directories(example PUBLIC 
                           #"${PROJECT_BINARY_DIR}"
                           #"${PROJECT_SOURCE_DIR}/StringUtilities"
                           #"${PROJECT_SOURCE_DIR}/JSONUtilities")
include_directories("${PROJECT_BINARY_DIR}"
                    "${PROJECT_SOURCE_DIR}/StringUtilities"
                    "${PROJECT_SOURCE_DIR}/JSONUtilities")
add_subdirectory(StringUtilities)
add_subdirectory(JSONUtilities)


enable_testing()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Werror=strict-prototypes")

#add_subdirectory(Examples)

