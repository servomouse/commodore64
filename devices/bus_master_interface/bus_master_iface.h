#pragma once

#include <stdint.h>
#include <stdlib.h>


uint32_t bus_get_value(void);
void bus_set_value(uint32_t value);
uint32_t bus_get_addr(void);
void bus_set_addr(uint32_t addr);
uint8_t bus_get_state(void);
void bus_set_state(uint8_t new_state);

// addr_range is an array: [start_addr, end_addr]
// Returns the pointer to the device's chip select
uint8_t *bus_map_device(uint32_t *addr_range, char *device_name);
