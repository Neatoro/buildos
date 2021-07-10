#include "devices/serial.h"
#include <stdio.h>

void kernel_main() {
    int returnCode = init_serial();
    if (returnCode == 0) {
        puts("Hello World!");
    }
}
