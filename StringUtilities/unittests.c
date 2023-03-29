#include <stdio.h>
#include "StringUtils.h"


static int testStripWSUntilControlCharacter(void){  
  char *jsonText = "  \t\n  \"hello\"\n";
  return stripWSUntilControlCharacter(jsonText, '"');
}


int main(int argc, char**argv){
  return !(testStripWSUntilControlCharacter() == 6);
}
