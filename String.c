#include "String.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char charAt_(struct String s, size_t index) {
	return (index < s.strlen_(s))
		? s.str[index]
		: '\0';
}

size_t strlen_(struct String s) {
    size_t len = 0;

    while (s.str[len] != '\0')
        len++;
    return len;
}

void forEach_(struct String s, void (*func)(char)) {
    size_t len = s.strlen_(s);

    for (size_t i = 0; i < len; i++) {
        func(s.str[i]);
    }
}

// char *slice_(struct String s, size_t start, size_t end) {
//     size_t len = s.strlen_(s);
//     if (!end)
//         end = len;
    
//     if (len <= 0 || start >= end || start > len || end > len)
//         return NULL;
//     char *str;

//     str = (char *) malloc(sizeof(char) * (end - start + 1));
//     if (!str)
//         return NULL;
 

//     size_t i = 0;

//     while (start < end)
//     {
//         str[i] = s.str[start];
//         i++;
//         start++;
//     }

//     str[i] = '\0';
//     printf("%s\n", str);
//     return str;
// }


char *slice_(struct String s, size_t start, ...) {
    size_t len = s.strlen_(s);
    size_t end;

    va_list args;
    va_start(args, start);

    end = va_arg(args, size_t);
    end = (end > len)? len : end;
    printf("%zu", end);
    va_end(args);
    if (start >= end || start > len || end > len)
        return NULL;

    size_t slice_len = end - start;
    char *str = (char *)malloc((slice_len + 1) * sizeof(char));
    if (!str)
        return NULL;

    for (size_t i = 0; i < slice_len; i++) {
        str[i] = s.str[start + i];
    }
    str[slice_len] = '\0';
    return str;
}

String newString(char *initialStr) {
    String s;
    s.str = initialStr;
    s.charAt_ = charAt_;
    s.strlen_ = strlen_;
    s.forEach_ = forEach_;
    s.slice_ = slice_;
    return s;
}