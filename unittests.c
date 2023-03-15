#include <stdio.h>
#include "CUnit/CUnitCI.h"
#include "JSON.h"
#include "StringUtils.h"

/* Test that one equals one */
static void test_simple_pass1(void) {
    CU_ASSERT_FATAL(1 == 1);
}

static void testStripWSUntilControlCharacter(void){
    char *jsonText = "  \t\n  hello\n";
    CU_ASSERT_FATAL(stripWSUntilControlCharacter(jsonText, QUOTATIONMARK) == 6)
}

CUNIT_CI_RUN(CU_MAIN_EXE_NAME,
             CUNIT_CI_TEST(test_simple_pass1));
