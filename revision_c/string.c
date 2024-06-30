#include "string.h"
#include <stdarg.h>

// Create a new CustomString
CustomString* createCustomString(const char* str) {
    CustomString* newStr = (CustomString*)malloc(sizeof(CustomString));
    newStr->value = strdup(str);
    return newStr;
}

// Destroy the CustomString
void destroyCustomString(CustomString* str) {
    if (str) {
        free(str->value);
        free(str);
    }
}

// Convert to upper case
char* toUpper(const CustomString* str) {
    char* result = strdup(str->value);
    for (int i = 0; result[i]; i++) {
        result[i] = toupper(result[i]);
    }
    return result;
}

// Convert to lower case
char* toLower(const CustomString* str) {
    char* result = strdup(str->value);
    for (int i = 0; result[i]; i++) {
        result[i] = tolower(result[i]);
    }
    return result;
}

// Capitalize first letter
char* capitalize(const CustomString* str) {
    char* result = strdup(str->value);
    if (result[0]) {
        result[0] = toupper(result[0]);
        for (int i = 1; result[i]; i++) {
            result[i] = tolower(result[i]);
        }
    }
    return result;
}

// Reverse the string
char* reverse(const CustomString* str) {
    size_t len = strlen(str->value);
    char* result = (char*)malloc(len + 1);
    for (size_t i = 0; i < len; i++) {
        result[i] = str->value[len - i - 1];
    }
    result[len] = '\0';
    return result;
}

// Get length of the string
size_t length(const CustomString* str) {
    return strlen(str->value);
}

// String comparison
int equals(const CustomString* str1, const CustomString* str2) {
    return strcmp(str1->value, str2->value) == 0;
}

int equalsIgnoreCase(const CustomString* str1, const CustomString* str2) {
    char* lowerStr1 = toLower(str1);
    char* lowerStr2 = toLower(str2);
    int result = strcmp(lowerStr1, lowerStr2) == 0;
    free(lowerStr1);
    free(lowerStr2);
    return result;
}

// Concatenate strings
CustomString* concat(const CustomString* str, const char* other) {
    size_t newLength = strlen(str->value) + strlen(other) + 1;
    char* newValue = (char*)malloc(newLength);
    strcpy(newValue, str->value);
    strcat(newValue, other);

    CustomString* newStr = (CustomString*)malloc(sizeof(CustomString));
    newStr->value = newValue;
    return newStr;
}

// Concatenate multiple strings
CustomString* concatMultiple(const CustomString* str, int count, ...) {
    va_list args;
    va_start(args, count);

    size_t totalLength = strlen(str->value);
    for (int i = 0; i < count; i++) {
        const char* nextStr = va_arg(args, const char*);
        totalLength += strlen(nextStr);
    }

    char* newValue = (char*)malloc(totalLength + 1);
    strcpy(newValue, str->value);

    va_start(args, count); // Restart argument list
    for (int i = 0; i < count; i++) {
        const char* nextStr = va_arg(args, const char*);
        strcat(newValue, nextStr);
    }
    va_end(args);

    CustomString* newStr = (CustomString*)malloc(sizeof(CustomString));
    newStr->value = newValue;
    return newStr;
}