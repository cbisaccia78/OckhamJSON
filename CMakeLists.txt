cmake_minimum_required(VERSION 3.26)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY"

project(
	OckhamJSON 
	0.0.0.0 
	"Parser/Generator of RFC JSON in C"
        "https://gitlab.com/utilities6655811/OckhamJSON"
	C
)
configure_file(JSON.h.in JSON.h)
enable_testing()

set(
	CMAKE_C_FLAGS 
	"${CMAKE_C_FLAGS} 
	-Wall -Werror -Werroe=strict-prototypes"
)

add_subdirectory(OckhamJSON)
add_subdirectory(Tests)
add_subdirectory(Examples)
