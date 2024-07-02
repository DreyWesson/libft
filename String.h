#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct String {
    char *str;
    char (*charAt_)(struct String *, size_t);
    size_t (*strlen_)(struct String *);
    void (*forEach_)(struct String *, void (*func)(char));
    struct String (*slice_)(struct String*, size_t, ...);
} String;

char charAt_(struct String *s, size_t index);
size_t strlen_(struct String *s);
void forEach_(struct String *s, void (*func)(char));
struct String slice_(struct String *s, size_t start, ...);
String newString(char *initialStr);

#endif
