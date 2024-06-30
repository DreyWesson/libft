#ifndef CUSTOM_STRING_H
#define CUSTOM_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the CustomString structure
typedef struct {
    char* value;
} CustomString;

// Function prototypes
CustomString* createCustomString(const char* str);
void destroyCustomString(CustomString* str);
char* toUpper(const CustomString* str);
char* toLower(const CustomString* str);
char* capitalize(const CustomString* str);
char* reverse(const CustomString* str);
size_t length(const CustomString* str);
int equals(const CustomString* str1, const CustomString* str2);
int equalsIgnoreCase(const CustomString* str1, const CustomString* str2);
CustomString* concat(const CustomString* str, const char* other);
CustomString* concatMultiple(const CustomString* str, int count, ...);

#endif // CUSTOM_STRING_H