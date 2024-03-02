#include <stdio.h>
#include <limits.h>

#ifndef INTTYPES
#include <inttypes.h>
#endif

#define _itoa(a,b,c) itoa(a,b,c)
#define _atoi64(x) atol(x)
#define __int64 long long //typedef not working with `unsigned` in front

#define M_PI       3.14159265358979323846   // pi
#define M_PI_2     1.57079632679489661923   // pi/2
#define M_PI_4     0.785398163397448309616  // pi/4
#define M_1_PI     0.318309886183790671538  // 1/pi
#define M_2_PI     0.636619772367581343076  // 2/pi
#define _MAX_PATH PATH_MAX
#define LONG_LONG_MAX LLONG_MAX
//#define bool bool_t // behebt das das problem??


#ifndef __ssize_t_defined
typedef __ssize_t ssize_t;
# define __ssize_t_defined
#endif
typedef unsigned int uint;
typedef __int8_t __int8;

// not c standard, but posix
char* strdup(const char*);
char* index(const char *string, int c);
char* strtok(char str[], const char *delims);
char *strtok_r(char *str, const char *delim, char **saveptr);

#ifndef EXTRACTING

#ifndef MIN_MAX
#define min(a, b)  (((a) < (b)) ? (a) : (b))
#define max(a, b)  (((a) > (b)) ? (a) : (b))
#endif

#ifndef BOOLTYPE
#define true 1
#define false 0
#define bool _Bool
#endif

#ifndef ITOA
char* itoa(int, char *, int);
#endif

#ifndef GITHUB
char* _ui64toa(uint64_t, char *, int);
void _sleep(unsigned int);
int getch(void);


// included in c11, but optional annex
typedef int errno_t;
errno_t fopen_s( FILE **,
                 const char *,
                 const char *);
#endif

#endif // EXTRACTING