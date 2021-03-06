#include "serial.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/io.h>

int init_serial() {
    outb(PORT + 1, 0x00);
    outb(PORT + 3, 0x80);
    outb(PORT + 0, 0x03);
    outb(PORT + 1, 0x00);
    outb(PORT + 3, 0x03);
    outb(PORT + 2, 0xC7);
    outb(PORT + 4, 0x0B);
    outb(PORT + 4, 0x1E);
    outb(PORT + 0, 0xAE);

    if (inb(PORT + 0) != 0xAE) {
        return 1;
    }

    outb(PORT + 4, 0x0F);
    return 0;
}

void write_serial(uint8_t value) {
    while ((inb(PORT + 5) & 0x20) == 0);
    outb(PORT, value);
}

int putchar(int character) {
    write_serial((uint8_t) character);
    return character;
}

int puts(const char* characters) {
    size_t length = strlen(characters);
    for (size_t i = 0; i < length; ++i) {
        putchar(characters[i]);
    }
    putchar('\n');
    return 1;
}
