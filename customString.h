#ifndef CUSTOM_STRING_H
# define CUSTOM_STRING_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

char *_strstr(const char *haystack, const char *needle);
char *_strchr(const char *s, int c);
int _strcmp(const char *s1, const char *s2);
void _bzero(void *s, size_t n);
void *_memset(void *b, int c, size_t len);
void *_memchr(const void *s, int c, size_t n);
void *_memmove(void *dst, const void *src, size_t len);
size_t _strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
char *_strdup(const char *s1);
size_t _strlen(const char *s);
void *_memcpy(void *restrict dst, const void *restrict src, size_t n);
int _atoi(const char *str);
char	*_substr(char const *s, unsigned int start, size_t len);
char *_strjoin(char const *s1, char const *s2);
char *_strtrim(char const *s1, char const *set);
char **_split(char const *s, char c);
char *_itoa(int n);

#endif