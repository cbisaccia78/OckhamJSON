include(CTest)

create_test_sourcelist(
  JSONTests
  JSONTests.c
  EqualsParse.c
  ParseNumber.c
)
add_executable(jsonTests MACOSX_BUNDLE ${JSONTests})
target_link_libraries(jsonTests PUBLIC jsonutils stringutils)
# remove the test driver source file
set (TestsToRun ${JSONTests})
remove (TestsToRun JSONTests.c)

# Add all the ADD_TEST for each test
foreach (test ${TestsToRun})
  get_filename_component (TName ${test} NAME_WE)
  add_test (NAME ${TName} COMMAND jsonTests ${TName})
endforeach ()

create_test_sourcelist(
  StringUtilityTests
  StringTests.c
  Equals.c
  Contains.c
  StripLeadingWhiteSpace.c
  ParseUntilControlCharacter.c
  StripUntilControlCharacter.c
  StripWSUntilControlCharacter.c
  GetLine.c
  GetAll.c
)
add_executable(StringUtilTests MACOSX_BUNDLE ${StringUtilityTests})
target_link_libraries(StringUtilTests PUBLIC stringutils)

# remove the test driver source file
set (TestsToRun ${StringUtilityTests})
remove (TestsToRun StringTests.c)

# Add all the ADD_TEST for each test
foreach (test ${TestsToRun})
  get_filename_component (TName ${test} NAME_WE)
  add_test (NAME ${TName} COMMAND StringUtilTests ${TName})
endforeach ()
