#ifndef __IO__H
#define __IO__H

#include <stdint.h>

inline void outb(uint16_t port, uint8_t value) {
    asm volatile("outb %0, %1" ::"a"(value), "Nd"(port));
}

inline uint8_t inb(uint16_t port) {
    uint8_t value;
    asm volatile("inb %1, %0" : "=a"(value) : "Nd"(port));
    return value;
}

#endif
