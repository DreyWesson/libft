#include "String.h"
#include <stdio.h>

void printChar(char c) {
    printf("%c ", c);
}

int main() {
    String myString = newString("Apple, Banana, Kiwi");
    
    char * ptr = myString.slice_(myString, 7);
    (void)ptr;
    // printf("%s\n", ptr);
    // // myString.charAt_(myString, 0);
    // // myString.strlen_(myString);
    // // myString.forEach_(myString, printChar);

    // String myString = newString("Hello, World!");

    // char ch = myString.charAt_(myString, 0);
    // printf("Character at index 0: %c\n", ch);

    // ch = myString.charAt_(myString, 7);
    // printf("Character at index 7: %c\n", ch);

    // size_t len = myString.strlen_(myString);
    // printf("Length of the string: %zu\n", len);

    // char *slicedString1 = myString.slice_(myString, 7, 12);
    // printf("Sliced string (7, 12): %s\n", slicedString1);
    // free(slicedString1); // Free the allocated memory

    // char *slicedString2 = myString.slice_(myString, 7); // Only start provided
    // printf("Sliced string (7): %s\n", slicedString2);
    // free(slicedString2); // Free the allocated memory

    return 0;
}
