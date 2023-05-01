
include(CTest)

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