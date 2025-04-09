#pragma once

#include <stdint.h>
#include <stdlib.h>
#include "bus_controller_header.h"

#define BUS_DIRECTION_READ  0
#define BUS_DIRECTION_WRITE 1

void bus_init(bus_device_iface_t *iface);
uint8_t bus_selected(uint32_t idx);
uint32_t bus_direction(void);
uint32_t bus_read(void);
void bus_write(uint32_t data);
