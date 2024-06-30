#include "customString.h"

char	*_strstr(const char *haystack, const char *needle)
{
	int	primary;
	int	head;
	int	tail;

	primary = 0;
	if (!needle)
		return ((char *)needle);
	while (haystack[primary] != '\0')
	{
		head = 0;
		tail = 0;
		if (haystack[primary] == needle[head])
		{
			tail = primary;
			while ((haystack[tail] != '\0' && needle[head] != '\0')
				&& haystack[tail] == needle[head])
			{
				tail++;
				head++;
			}
			if (needle[head] == '\0')
			{
				return (char *)(haystack + primary);
			}
		}
		primary++;
	}
	return (NULL);
}

int _strcmp(const char *s1, const char *s2) {
    const unsigned char *str = (const unsigned char *)s1;
    const unsigned char *cs = (const unsigned char *)s2;

    while (*str != '\0' && *cs != '\0')
    {
        if (*str != *cs)
            return *str - *cs;
        str++;
        cs++;
    }
    return *str - *cs;
}

void _bzero(void *s, size_t n) {
    unsigned char * p = (unsigned char *)s;

    while (n > 0) {
        n--;
        p[n] = 0;
    }
}

void *_memset(void *b, int c, size_t len) {
    unsigned char * d = (unsigned char *) b;
    unsigned char e = (unsigned char) c;

    if (len == 0)
        return (b);
    size_t i = 0;

    while (i < len) {
        d[i] = e;
        i++;
    }
    return (void *)(d);
}

void *_memchr(const void *s, int c, size_t len) {
    const unsigned char * d = (const unsigned char *)s;
    const unsigned char e = (unsigned char) c;
    size_t i = 0;
    if (len == 0)
        return (void *)(s);
    
    while (i < len) {
        if (d[i] == e)
            return (void *)(d + i);
        i++;
    }

    return (void *)(s); 
}

// void *_memcpy(void *restrict dst, const void *restrict src, size_t n) {

// }

size_t _strlen(const char *s) {
    size_t i = 0;

    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}

char	*_substr(char const *s, unsigned int start, size_t len)
{
    size_t length = _strlen(s);
    if (start >= length || length == 0)
        return (NULL);
    char *ptr = (char *) malloc ((len + 1) * sizeof(char));

    size_t i = 0;
    while (s[start])
    {
        if (i == len)
            break;
        ptr[i] = s[start];
        start++;
        i++;
    }
    ptr[i] = '\0';
    return ptr;
}

char *_strdup(const char *s1) {
    size_t len = _strlen(s1);
    if (!s1)
        return (NULL);
    char *str = (char *)malloc((len + 1) * sizeof(char));
    if (!str)
        return (NULL);
    int i = 0;
    while (s1[i] != '\0')
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return (char *)str;
}

int _atoi(const char *str) {
    int i = 0;
    int neg = 0;
    int nbr = 0;

    while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
           str[i] == '\v' || str[i] == '\f' || str[i] == '\r')) {
        i++;
    }

    if (str[i] != '\0' && (str[i] == '-' || str[i] == '+')) {
        if (str[i] == '-')
            neg = 1;
        i++;
    }

    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
            nbr = (nbr * 10) + (str[i] - '0');
        else
            break;
        i++;
    }

    return neg ? (-nbr) : nbr;
}

char *_strjoin(char const *s1, char const *s2) {
    size_t len1 = _strlen(s1);
    size_t len2 = _strlen(s2);

    char *ptr = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    int i = 0;

    if (s1) {
        while (s1[i] != '\0')
        {
            ptr[i] = s1[i];
            i++;
        }
    }
    int j = 0;
    if (s2) {
        while (s2[j] != '\0')
        {
            ptr[i] = s2[j];
            i++;
            j++;
        } 
    }
    ptr[i] = '\0';
    return (ptr);
}
