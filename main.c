#include "String.h"
#include <stdio.h>

void printChar(char c) {
    printf("%c ", c);
}

int main() {
    String myString = newString("Apple, Banana, Kiwi");

    printf("%c\n", myString.charAt_(&myString, 7));
    printf("%zu\n", myString.strlen_(&myString));
    myString.forEach_(&myString, printChar);

    struct String sliced = myString.slice_(&myString, 7, 13);

    printf("\n%s\n", sliced.str);

    free(sliced.str);
    return 0;
}
