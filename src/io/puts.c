#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <internal/io.h>

int puts(const char *str){
    ssize_t length = 0;
    const char *ptr = str;
    while (*ptr != '\0') {
        length++;
        ptr++;
    }
    if (write(1, str, strlen(str)) != length)
    return -1;
    if (write(1, "\n", 1) != 1)
    return -1;
    return 1;
}
