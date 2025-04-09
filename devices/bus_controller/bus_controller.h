#pragma once

#include <stdint.h>
#include <stdlib.h>
#include "bus_controller_header.h"


uint32_t bus_get_value(void);
void bus_set_value(uint32_t value);
uint32_t bus_get_addr(void);
void bus_set_addr(uint32_t addr);
uint8_t bus_get_state(void);
void bus_set_state(uint8_t new_state);
bus_master_iface_t *bus_get_master_iface(void);
bus_device_iface_t *bus_get_device_iface(void);
uint8_t bus_get_cs(uint32_t idx);

// addr_range is an array: [start_addr, end_addr]
// Returns an index in the CS array, assigned to the device
uint8_t bus_map_device(uint32_t *addr_range, char *device_name);
