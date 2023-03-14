#include <stdio.h>
#include "External/CUnit/CUnitCI.h"
#include "JSON.h"
#include "StringUtils.h"

#define LINELIMIT 4096

/* Test that one equals one */
static void test_simple_pass1(void) {
    CU_ASSERT_FATAL(1 == 1);
}
CUNIT_CI_RUN(CU_MAIN_EXE_NAME,
             CUNIT_CI_TEST(test_simple_pass1));

int main(int argc, char **argv){
    /*
        int c, i = 0;
        char jsonText[LINELIMIT];
        
        getAll(jsonText, LINELIMIT);

        DeSerializationTemplate *t;
        Storage *s;
        
        deserializeFromTemplate(jsonText, t, s);
    */

    char *jsonText = "  \t\n  hello\n";
    //getLine(jsonText, LINELIMIT);
    printf("Echo: %s\n", jsonText);
    int wsStripped = stripWSUntilControlCharacter(jsonText, QUOTATIONMARK);
    printf("Number of white space parsed: %d\n", wsStripped);
    printf("Result: %s\n", jsonText + wsStripped);
}