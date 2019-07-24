#include <stdio.h>
#include <string.h>
#include "day1.h"

int main() {
    char *text = "This is a test Text";
    printf("\n%s",reverseText(text,strlen(text)));
    return 0;
}