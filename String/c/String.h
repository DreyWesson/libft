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
    struct String (*strrev_)(struct String *);
    size_t (*strlen_)(struct String *);
    char (*charAt_)(struct String *, size_t);
    void (*forEach_)(struct String *, void (*func)(char));
    struct String (*slice_)(struct String*, size_t, ...);
    char *(*strcpy_)(struct String *self, char *dest, const char *src);

} String;

char charAt_(struct String *s, size_t index);
size_t strlen_(struct String *s);
void forEach_(struct String *s, void (*func)(char));
struct String slice_(struct String *s, size_t start, ...);
struct String strrev_(struct String *s);
char *strcpy_(struct String *self, char *dest, const char *src);

String stringConstructor(char *initialStr);

#endif
