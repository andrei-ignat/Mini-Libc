#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <internal/io.h>
#include <internal/syscall.h>
#include <time.h>

int nanosleep(const struct timespec *t1, struct timespec *t2) {
    int ret = syscall(__NR_nanosleep, t1, t2);
	if (ret < 0){
		errno = -ret;
		return -1;
	}
    return ret;
}
