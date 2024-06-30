#include "string.h"

int main() {
    CustomString* myString = createCustomString("hello");

    char* upper = toUpper(myString);
    printf("Upper case: %s\n", upper);
    free(upper);

    char* reversed = reverse(myString);
    printf("Reversed: %s\n", reversed);
    free(reversed);

    printf("Length: %zu\n", length(myString));

    CustomString* anotherString = createCustomString(" world");
    CustomString* combinedString = concat(myString, anotherString->value);
    printf("Combined: %s\n", combinedString->value);

    CustomString* multiConcat = concatMultiple(myString, 3, " ", "and", anotherString->value);
    printf("Multi concat: %s\n", multiConcat->value);

    destroyCustomString(myString);
    destroyCustomString(anotherString);
    destroyCustomString(combinedString);
    destroyCustomString(multiConcat);

    return 0;
}