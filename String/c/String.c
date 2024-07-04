#include "String.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char charAt_(struct String *s, size_t index) {
	return (index < s->strlen_(s))
		? s->str[index]
		: '\0';
}

size_t strlen_(struct String *s) {
    size_t len = 0;

    while (s->str[len] != '\0')
        len++;
    return len;
}

void forEach_(struct String *s, void (*func)(char)) {
    size_t len = s->strlen_(s);

    for (size_t i = 0; i < len; i++) {
        func(s->str[i]);
    }
}

struct String slice_(struct String *s, size_t start, ...) {
    size_t len = s->strlen_(s);
    size_t end;
    struct String ss = stringConstructor("");

    va_list args;
    va_start(args, start);
    end = va_arg(args, size_t);
    end = (end > len)? len : end;
    va_end(args);

    if (start >= end || start > len)
        return ss;

    size_t slice_len = end - start;
    char *str = (char *)malloc((slice_len + 1) * sizeof(char));
    if (!str)
        return ss;

    for (size_t i = 0; i < slice_len; i++) {
        str[i] = s->str[start + i];
    }
    str[slice_len] = '\0';
    ss.str = str;
    return ss;
}

struct String strrev_(struct String *s) {
    if (!s || !s->str)
        return (*s);
    size_t len = s->strlen_(s);

    char *str = (char *) malloc(sizeof(char) * (len + 1));
    size_t head = len - 1;
    size_t tail = 0;
    while (tail <= head)
    {
        str[tail] = s->str[head];
        str[head] = s->str[tail];
        tail++;
        head--;
    }
    str[len] = '\0';
    s->str = str;
    return *s;
}

char *strcpy_(struct String *self, char *dest, const char *src) {
    (void) self;
    size_t i = 0;
    if (!src)
        return (dest);

    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    printf("%s\n", dest);
    return (dest);
}



String stringConstructor(char *initialStr) {
    String s;
    s.str = initialStr;
    s.charAt_ = charAt_;
    s.strlen_ = strlen_;
    s.forEach_ = forEach_;
    s.slice_ = slice_;
    s.strrev_ = strrev_;
    s.strcpy_ = strcpy_;
    return s;
}
