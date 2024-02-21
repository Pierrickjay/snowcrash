#define _GNU_SOURCE
#include <dlfcn.h>
#include <unistd.h>

uid_t getuid(void) {
    return 4242;
}
