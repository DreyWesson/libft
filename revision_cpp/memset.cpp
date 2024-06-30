#include <iostream>

void *_memset(void *b, int c, size_t len)
{
    int i = 0;

    unsigned char *(p) = static_cast<unsigned char *>(b);
    unsigned char (cc) = static_cast<unsigned char>(c);
    while (i < len)
    {
        p[i] = cc;
        i++;
    }
    return (b);
}

void *
     memchr(const void *s, int c, size_t n)
{
    int i = 0;

    unsigned char cc = static_cast<unsigned char>(c);
    const unsigned char *ss = static_cast<const unsigned char *>(s);
    
    while (i < n)
    {
        if (ss[i] == cc)
            return ((void *) ss + i);
        i++;
    }
    return nullptr;
}

void *
     memchr(const void *s, int c, size_t n)
{
    int i = 0;

    unsigned char cc = static_cast<unsigned char>(c);
    const unsigned char *ss = static_cast<const unsigned char *>(s);
    
    while (i < n)
    {
        if (ss[i] == cc)
            return ((void *) ss + i);
        i++;
    }
    return nullptr;
}

void *memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *d = static_cast<unsigned char *>(dst);
    const unsigned char *ds = static_cast<const unsigned char *>(src);

    while (n>=0)
    {
        n--;
        d[n] = ds[n];
    }

    return (void *)d;
}

void _bzero(void *s, size_t n)
{
    if (n == 0)
        return;
    int i = 0;
    unsigned char *st = static_cast<unsigned char *>(s);

    while (i < n)
    {
        st[i] = 0;
        i++;
    }
}


char *_strstr(const char *haystack, const char *needle)
{
    int primary = 0;
    if (needle[0] == '\0')
        return const_cast<char *>(haystack);

    while (haystack[primary] != '\0')
    {
        int lead = 0;
        int follow = 0;

        if (haystack[primary] == needle[lead])
        {
            follow = primary;
            while ((haystack[follow] != '\0' && needle[lead] != '\0') && haystack[follow] == needle[lead])
            {
                lead++;
                follow++;
            }
            if (needle[lead] == '\0')
            {
                return const_cast<char *>(&haystack[primary]);
            } 
        }
        primary++;
    }

    return nullptr;
}