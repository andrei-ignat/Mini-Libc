#ifndef __TIME_H__
#define __TIME_H__	1

#ifdef __cplusplus
extern "C" {
#endif

typedef long time_t;

struct timespec {
    time_t tv_sec;
    long int tv_nsec;
};
int nanosleep(const struct timespec *r1, struct timespec *r2);

#ifdef _cplusplus
}
#endif

#endif
