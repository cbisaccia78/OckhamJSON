#include <stdio.h>
#include "../StringUtils.h"


static int testStripWSUntilControlCharacter(void){  
  char *jsonText = "  \t\n  \"hello\"\n";
  return stripWSUntilControlCharacter(jsonText, '"');
}

int StripWSUntilControlCharacter(int argc, int **argv){
    return !(testStripWSUntilControlCharacter() == 6);
}