#include "JSON.h"
#include "JSONUtils.h"

/*
  * UNTESTED
*/
int parsePopulate(char **jsonDataText, char **jsonTemplateText, Storage *s){
    return 0;
}

void deserializeFromTemplate(char **jsonText, char **templateText, Storage *s){
    //Parse JSON text using the help of the tree nodes
    parsePopulate(jsonText, templateText, s);
}
