#include "customString.h"

int main() {
    char buffer[10] = "Hello";
    char buffer2[10] = "*world!";
    printf("%s", _strjoin(buffer, buffer2));
    // void *b = buffer;

    // unsigned char *str = _memchr(b, 'r', sizeof(buffer));

    // Print buffer contents
    // printf("Buffer after _memset: %s", str);
    
    // printf("%d", _atoi(buffer));

    return 0;
}