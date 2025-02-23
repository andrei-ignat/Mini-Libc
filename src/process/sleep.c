#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <internal/io.h>
#include <internal/syscall.h>
#include <time.h>

unsigned int sleep(unsigned int seconds){
    struct timespec r1, r2;
    r1.tv_nsec = 0;
    r1.tv_sec = (time_t)seconds;
    if (nanosleep(&r1, &r2) == -1)
    return 0;
    return 1;
}
