
include(CTest)

create_test_sourcelist(
  JSONTests
  JSONTests.c
  Parse.c
  DeserializeFromTemplate.c
  EqualsParse.c
)
add_executable(JSONTests MACOSX_BUNDLE ${JSONTests})
# remove the test driver source file
set (TestsToRun ${StringUtilityTests})
remove (TestsToRun StringTests.c)

# Add all the ADD_TEST for each test
foreach (test ${TestsToRun})
  get_filename_component (TName ${test} NAME_WE)
  add_test (NAME ${TName} COMMAND StringUtilTests ${TName})
endforeach ()