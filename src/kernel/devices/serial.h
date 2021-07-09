#ifndef __SERIAL_H
#define __SERIAL_H

#include <stdint.h>

#define PORT 0x3F8

int init_serial();
void write_serial(uint8_t value);

#endif
