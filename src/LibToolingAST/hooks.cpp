// Compile with: g++ -Wall -O2 -Wl,--no-as-needed -fpic -shared -ldl -o hooks.so hooks.cpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <regex>
#include <dlfcn.h>
#include <stdarg.h>
#include <unistd.h>

#include "hooks.h"

#define O_RDONLY	     00

/*
 * If we replace external calls with tigress, the program will use dlsym to get the addresses.
 * In that case, our hooks will not work in all cases, so we have also to hook dlsym to intercept
 * these requests. But we have to ignore requests from within our hooks
 */
extern "C" void *_dl_sym(void *, const char *, void *);
static int callFromWithin = 0;

void *dlsym(void *handle, const char *symbol) {
    using dlsym_t = void *(*)(void *, const char *);
    static dlsym_t real_dlsym = nullptr;
    if (real_dlsym == nullptr) {
        real_dlsym = reinterpret_cast<dlsym_t>(dlvsym(RTLD_NEXT, "dlsym", "GLIBC_2.2.5"));
        char *error = dlerror();
        if (error != nullptr) {
            fprintf(stderr, "%s\n", error);
            exit(1);
        }
    }
    if (callFromWithin) {
        return real_dlsym(handle, symbol);
    }

    if (strcmp(symbol, "dlsym") == 0) {
        return (void *) dlsym;
    } else if (strcmp(symbol, "scanf") == 0) {
        return (void *) scanf;
    }
    void *ret = real_dlsym(handle, symbol);
#ifdef DEBUG_DLSYM
    fprintf(stderr, "looking for symbol %s: %p\n", symbol, ret);
#endif
    return ret;
}

/*
 * For internal use in this hooks to avoid endless recursion
 */
void *__internal_dlsym(void *handle, const char *symbol) {
    callFromWithin = 1;
    void *addr = dlsym(handle, symbol);
    callFromWithin = 0;
    return addr;
}

int printf(const char *format, ...) {
#ifdef DEBUG
    fprintf(stderr, "printing with formatstr %s", format);
#endif
    std::string fmtStr(format);
    fmtStr = std::regex_replace(fmtStr, std::regex("%I64d"), "%lld");
    fmtStr = std::regex_replace(fmtStr, std::regex("%llf"), "%lf");
#ifdef DEBUG
    fprintf(stderr, "formatstr converted to %s", fmtStr.c_str());
#endif
    va_list args;
    va_start(args, format);
    int ret = vprintf(fmtStr.c_str(), args);
    va_end(args);
    return ret;
};

int sprintf(char *str, const char *format, ...) {
#ifdef DEBUG
    fprintf(stderr, "sprinting with formatstr %s\n", format);
#endif
    std::string fmtStr(format);
    fmtStr = std::regex_replace(fmtStr, std::regex("%I64d"), "%lld");
    fmtStr = std::regex_replace(fmtStr, std::regex("%llf"), "%lf");
#ifdef DEBUG
    fprintf(stderr, "formatstr converted to %s\n", fmtStr.c_str());
#endif
    va_list args;
    va_start(args, format);
    int ret = vsprintf(str, fmtStr.c_str(), args);
    va_end(args);
    return ret;
};

extern "C" int __isoc99_scanf(const char *format, ...) {
#ifdef DEBUG
    fprintf(stderr, "scanning with formatstr %s\n", format);
#endif
    std::string fmtStr(format);
    fmtStr = std::regex_replace(fmtStr, std::regex("%I64d"), "%lld");
#ifdef DEBUG
    fprintf(stderr, "formatstr converted to %s\n", fmtStr.c_str());
#endif
    va_list args;
    va_start(args, format);
    int ret = vscanf(fmtStr.c_str(), args);
    va_end(args);
    return ret;
};

int scanf(const char *format, ...) {
#ifdef DEBUG
    fprintf(stderr, "scanning with formatstr %s\n", format);
#endif
    std::string fmtStr(format);
    fmtStr = std::regex_replace(fmtStr, std::regex("%I64d"), "%lld");
#ifdef DEBUG
    fprintf(stderr, "formatstr converted to %s\n", fmtStr.c_str());
#endif
    va_list args;
    va_start(args, format);
    int ret = vscanf(fmtStr.c_str(), args);
    va_end(args);
    return ret;
};

int system(const char *command) {
    using system_t = int (*)(const char *);
    static system_t real_system = nullptr;
    if (real_system == nullptr) {
        real_system = reinterpret_cast<system_t>(__internal_dlsym(RTLD_NEXT, "system"));
        char *error = dlerror();
        if (error != nullptr) {
            fprintf(stderr, "%s\n", error);
            exit(1);
        }
    }
#ifdef DEBUG
    fprintf(stderr, "calling system with command: %s\n", command);
#endif
    if (strcmp(command, "pause") == 0) {
        return 0;
    }

    return real_system(command);
}

FILE *freopen(const char *filename, const char *mode, FILE *stream) {
    using reopen_t = FILE *(*)(const char *, const char *, FILE *);
    static reopen_t real_freopen = nullptr;
    if (real_freopen == nullptr) {
        real_freopen = reinterpret_cast<reopen_t>(__internal_dlsym(RTLD_NEXT, "freopen"));
        char *error = dlerror();
        if (error != nullptr) {
            fprintf(stderr, "%s\n", error);
            exit(1);
        }
    }
#ifdef DEBUG
    fprintf(stderr, "opening freopen: %s with mode %s\n", filename, mode);
#endif
    if (std::string(mode).find("r") != std::string::npos) {
        return stdin;
    } else if (std::string(mode).find("w") != std::string::npos || std::string(mode).find("a") != std::string::npos) {
        return stdout;
    }
#ifdef DEBUG
    fprintf(stderr, "Fallback to real freopen\n");
#endif
    return real_freopen(filename, mode, stream);
}

FILE *fopen(const char *filename, const char *mode) {
    using fopen_t = FILE *(*)(const char *, const char *);
    static fopen_t real_fopen = nullptr;
    if (real_fopen == nullptr) {
        real_fopen = reinterpret_cast<fopen_t>(__internal_dlsym(RTLD_NEXT, "fopen"));
        char *error = dlerror();
        if (error != nullptr) {
            fprintf(stderr, "%s\n", error);
            exit(1);
        }
    }
#ifdef DEBUG
    fprintf(stderr, "opening fopen: %s with mode %s\n", filename, mode);
#endif
    if (std::string(mode).find("r") != std::string::npos) {
#ifdef DEBUG
    fprintf(stderr, "returning stdin %p\n", stdin);
#endif
        return stdin;
    } else if (std::string(mode).find("w") != std::string::npos || std::string(mode).find("a") != std::string::npos) {
#ifdef DEBUG
    fprintf(stderr, "returning stdout %p\n", stdout);
#endif
        return stdout;
    }
    return real_fopen(filename, mode);
}

int fclose(FILE *stream) {
    using fclose_t = int (*)(FILE *stream);
    static fclose_t real_fclose = nullptr;
    if (real_fclose == nullptr) {
        real_fclose = reinterpret_cast<fclose_t>(__internal_dlsym(RTLD_NEXT, "fclose"));
        char *error = dlerror();
        if (error != nullptr) {
            fprintf(stderr, "%s\n", error);
            exit(1);
        }
    }
#ifdef DEBUG
    fprintf(stderr, "closing fclose: %d\n", stream->_fileno);
#endif
    if (stream == stdin || stream == stdout) {
        return 0;
    }
    return real_fclose(stream);
}

extern "C" off_t lseek(int fd, off_t offset, int whence) {
#ifdef DEBUG
    fprintf(stderr, "lseek: fd %d offset %ld\n", fd, offset);
#endif
    return 10*1024*1024;
}

extern "C" int open(const char* pathname, int flags) {
    using open_t = int (*)(const char*, int);
    static open_t real_open = nullptr;
    if (real_open == nullptr) {
        real_open = reinterpret_cast<open_t>(__internal_dlsym(RTLD_NEXT, "open"));
        char *error = dlerror();
        if (error != nullptr) {
            fprintf(stderr, "%s\n", error);
            exit(1);
        }
    }
#ifdef DEBUG
    fprintf(stderr, "open: %s\n", pathname);
#endif
    if (flags != O_RDONLY) {
        return real_open(pathname, flags);
    }
    return STDIN_FILENO;
}

#ifdef DEBUG
std::string openmode2String(std::ios_base::openmode __mode) {
    std::string mode{};
    if (__mode & std::ios_base::openmode::_S_ios_openmode_end) {
        mode += "end";
    }
    if (__mode & std::ios_base::openmode::_S_ios_openmode_max) {
        if (!mode.empty())
            mode += ", ";
        mode += "max";
    }
    if (__mode & std::ios_base::openmode::_S_ios_openmode_min) {
        if (!mode.empty())
            mode += ", ";
        mode += "min";
    }
    if (__mode & std::ios_base::openmode::_S_app) {
        if (!mode.empty())
            mode += ", ";
        mode += "app";
    }
    if (__mode & std::ios_base::openmode::_S_ate) {
        if (!mode.empty())
            mode += ", ";
        mode += "ate";
    }
    if (__mode & std::ios_base::openmode::_S_bin) {
        if (!mode.empty())
            mode += ", ";
        mode += "bin";
    }
    if (__mode & std::ios_base::openmode::_S_in) {
        if (!mode.empty())
            mode += ", ";
        mode += "in";
    }
    if (__mode & std::ios_base::openmode::_S_out) {
        if (!mode.empty())
            mode += ", ";
        mode += "out";
    }
    if (__mode & std::ios_base::openmode::_S_trunc) {
        if (!mode.empty())
            mode += ", ";
        mode += "trunc";
    }
    return mode;
}
#endif

/// ifstream constructor
void _ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode(
        std::basic_ifstream<char, std::char_traits<char>> *self, const char *__s, std::ios_base::openmode __mode) {
    using ifstream_t = void (*)(std::basic_ifstream<char, std::char_traits<char>> *, const char *,
                                std::ios_base::openmode);
    static ifstream_t real_ifstream = nullptr;
    if (real_ifstream == nullptr) {
        real_ifstream = reinterpret_cast<ifstream_t>(__internal_dlsym(RTLD_NEXT,
                                                                      "_ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode"));
        char *error = dlerror();
        if (error != nullptr) {
            fprintf(stderr, "%s\n", error);
            exit(1);
        }
    }
#ifdef DEBUG
    auto mode = openmode2String(__mode);
    fprintf(stderr, "opening ifstream: %s with mode %d (%s)\n", __s, __mode, mode.c_str());
#endif
    if (__mode & std::ios_base::openmode::_S_in) {
        return real_ifstream(self, "/dev/stdin", __mode);
    }
    return real_ifstream(self, __s, __mode);
}

/// ofstream constructor
void _ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode(
        std::basic_ofstream<char, std::char_traits<char>> *self, const char *__s, std::ios_base::openmode __mode) {
    using ofstream_t = void (*)(std::basic_ofstream<char, std::char_traits<char>> *, const char *,
                                std::ios_base::openmode);
    static ofstream_t real_ofstream = nullptr;
    if (real_ofstream == nullptr) {
        real_ofstream = reinterpret_cast<ofstream_t>(__internal_dlsym(RTLD_NEXT,
                                                                      "_ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode"));
        char *error = dlerror();
        if (error != nullptr) {
            fprintf(stderr, "%s\n", error);
            exit(1);
        }
    }
#ifdef DEBUG
    auto mode = openmode2String(__mode);
    fprintf(stderr, "opening ofstream: %s with mode %d (%s)\n", __s, __mode, mode.c_str());
#endif
    if (__mode & std::ios_base::openmode::_S_out) {
        return real_ofstream(self, "/dev/stdout", __mode);
    }
    return real_ofstream(self, __s, __mode);
}

/// ofstream open
void _ZNSt14basic_ofstreamIcSt11char_traitsIcEE4openEPKcSt13_Ios_Openmode(
        std::basic_ofstream<char, std::char_traits<char>> *self, const char *__s, std::ios_base::openmode __mode) {
    using ofstream_open_t = void (*)(std::basic_ofstream<char, std::char_traits<char>> *, const char *,
                                     std::ios_base::openmode);
    static ofstream_open_t real_ofstream = nullptr;
    if (real_ofstream == nullptr) {
        real_ofstream = reinterpret_cast<ofstream_open_t>(__internal_dlsym(RTLD_NEXT,
                                                                           "_ZNSt14basic_ofstreamIcSt11char_traitsIcEE4openEPKcSt13_Ios_Openmode"));
        char *error = dlerror();
        if (error != nullptr) {
            fprintf(stderr, "%s\n", error);
            exit(1);
        }
    }
#ifdef DEBUG
    auto mode = openmode2String(__mode);
    fprintf(stderr, "opening ofstream with open: %s with mode %d (%s)\n", __s, __mode, mode.c_str());
#endif
    if (__mode & std::ios_base::openmode::_S_out) {
        return real_ofstream(self, "/dev/stdout", __mode);
    }
    return real_ofstream(self, __s, __mode);
}

/// ifstream open
void _ZNSt14basic_ifstreamIcSt11char_traitsIcEE4openEPKcSt13_Ios_Openmode(
        std::basic_ifstream<char, std::char_traits<char>> *self, const char *__s, std::ios_base::openmode __mode) {
    using ifstream_open_t = void (*)(std::basic_ifstream<char, std::char_traits<char>> *, const char *,
                                     std::ios_base::openmode);
    static ifstream_open_t real_ifstream = nullptr;
    if (real_ifstream == nullptr) {
        real_ifstream = reinterpret_cast<ifstream_open_t>(__internal_dlsym(RTLD_NEXT,
                                                                           "_ZNSt14basic_ifstreamIcSt11char_traitsIcEE4openEPKcSt13_Ios_Openmode"));
        char *error = dlerror();
        if (error != nullptr) {
            fprintf(stderr, "%s\n", error);
            exit(1);
        }
    }
#ifdef DEBUG
    auto mode = openmode2String(__mode);
    fprintf(stderr, "opening ifstream with open: %s with mode %d (%s)\n", __s, __mode, mode.c_str());
#endif
    if (__mode & std::ios_base::openmode::_S_in) {
        return real_ifstream(self, "/dev/stdin", __mode);
    }
    return real_ifstream(self, __s, __mode);
}

/// for random_shuffle
int rand() {
    static int counter = 0;
    counter = counter % 500000000;
//    fprintf(stderr, "not-random rand: %d\n", counter);
    return counter++;
}

clock_t clock() {
    static clock_t time = 0;
    static long do_clock = 0;
    do_clock = (1 + do_clock) % 10;
    if (do_clock == 0)
        time++;
//    fprintf(stderr, "fake-time: %ld\n", time);
    return time;
}
