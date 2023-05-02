create_test_sourcelist(
  JSONTests
  JSONTests.c
  EqualsParse.c
  ParseNumber.c
)
add_executable(JSONTests MACOSX_BUNDLE ${JSONTests})
target_link_libraries(JSONTests PUBLIC jsonutils)
target_include_directories(JSONTests PUBLIC 
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}"
                           "${PROJECT_SOURCE_DIR}/StringUtilities")
# remove the test driver source file
set (TestsToRun ${JSONTests})
remove (TestsToRun JSONTests.c)

# Add all the ADD_TEST for each test
foreach (test ${TestsToRun})
  get_filename_component (TName ${test} NAME_WE)
  add_test (NAME ${TName} COMMAND JSONTests ${TName})
endforeach ()
