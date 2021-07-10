#ifndef __STRING_H
#define __STRING_H

#include <stddef.h>

inline size_t strlen(const char* data) {
    size_t length = 0;
    while (data[length]) {
        ++length;
    }
    return length;
}

#endif
