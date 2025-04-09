#include <stdio.h>
#include "bus_device_iface.h"
#include "utils.h"

bus_device_iface_t *bus_iface;

void bus_init(bus_device_iface_t *iface) {
    bus_iface = iface;
}

uint8_t bus_selected(uint32_t idx) {
    return bus_iface->get_cs(idx);
}

uint32_t bus_direction(void) {
    return bus_iface->get_direction();
}

uint32_t bus_read(void) {
    return bus_iface->read_data();
}

void bus_write(uint32_t data) {
    bus_iface->write_data(data);
}
