#include <stdio.h>
#include "bus_device_iface.h"
#include "utils.h"

uint32_t cs_idx;

void device_init(uint32_t idx) {
    cs_idx = idx;
    printf("Device initialized!\n");
}

void tick(void) {
    if(bus_selected(cs_idx)) {
        if(BUS_DIRECTION_READ == bus_direction()) {
            printf("Bus read value: 0x%X\n", bus_read());
        } else {
            printf("Writing 0xAA to the bus\n");
            bus_write(0xAA);
        }
    } else {
        printf("Device's bus interactions are disabled");
    }
}
