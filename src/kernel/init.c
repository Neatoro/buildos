#include "devices/serial.h"

void kernel_main() {
    int returnCode = init_serial();
    if (returnCode == 0) {
        write_serial(0x3D);
    }
}
