add_library(jsonutils JSONUtils.c)
add_dependencies(jsonutils stringutils)
target_include_directories(jsonutils PUBLIC 
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/StringUtilities")  
add_subdirectory(Tests)
