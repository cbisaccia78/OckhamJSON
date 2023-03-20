#include <stdio.h>
#include "JSON.h"
#include "StringUtils.h"



static void testStripWSUntilControlCharacter(void){  
  char *jsonText = "  \t\n  hello\n";
  CU_ASSERT_FATAL(stripWSUntilControlCharacter(jsonText, QUOTATIONMARK) == 6)
}


int main(int argc, char**argv){
  printf("Version Major: %s\nVersion Minor: %s\n", OckhamJSON_VERSION_MAJOR, OckhamJSON_VERSION_MINOR );
}
