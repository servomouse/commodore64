#include <stdio.h>
#include "bus_controller.h"
#include "utils.h"

#define DATA_BUS_WIDTH uint8_t
#define ADDR_BUS_WIDTH uint16_t
#define NUM_DEVICES 128

typedef struct {
    DATA_BUS_WIDTH data;
    ADDR_BUS_WIDTH address;
    uint8_t rw_enable;  // 0: all disable, 1: read enable, 2: write_enable
} cpu_bus_t;

typedef struct {
    ADDR_BUS_WIDTH start_address;
    ADDR_BUS_WIDTH end_address;
    uint8_t initialized;
    char *device_name;
} addr_range_t;

cpu_bus_t bus;
addr_range_t ranges[NUM_DEVICES];
uint8_t chip_select[NUM_DEVICES];       // Is set to 1 when the corresponding device is selected
uint32_t num_devices;

uint32_t bus_get_value(void) {
    return bus.data;
}

void bus_set_value(uint32_t value) {
    bus.data = value;
}

uint32_t bus_get_addr(void) {
    return bus.address;
}

void bus_set_addr(uint32_t addr) {
    bus.address = addr;
    for(uint32_t i=0; i<NUM_DEVICES; i++) {
        chip_select[i] = 0;
        if(ranges[i].initialized == 0) {
            if((addr >= ranges[i].start_address) && (addr < ranges[i].end_address)) {
                chip_select[i] = 1;
            }
        }
    }
}

uint8_t bus_get_state(void) {
    return bus.rw_enable;
}

void bus_set_state(uint8_t new_state) {
    bus.rw_enable = new_state;
}

uint8_t bus_get_cs(uint32_t idx) {
    return chip_select[idx];
}

// addr_range is an array: [start_addr, end_addr]
// Returns the pointer to the device's chip select
uint8_t *bus_map_device(uint32_t *addr_range, char *device_name) {
    uint32_t idx = 0, found = 0;
    for(uint32_t i=0; i<NUM_DEVICES; i++) {
        if(ranges[i].initialized == 0) {
            found = 1;
            ranges[i].start_address = addr_range[0];
            ranges[i].end_address = addr_range[1];
            ranges[i].initialized = 1;
            ranges[i].device_name = device_name;
            idx = i;
            break;
        } else {
            if((addr_range[0] >= ranges[i].start_address) && (addr_range[0] < ranges[i].end_address)) {
                printf("Error: overlapping address ranges, devices: %s and %s, ranges are: [0x%X:0x%X] and 0x%X\n",
                       ranges[i].device_name, device_name, ranges[i].start_address, ranges[i].end_address, addr_range[0]);
                exit(EXIT_FAILURE);
            } else if((addr_range[1] >= ranges[i].start_address) && (addr_range[1] < ranges[i].end_address)) {
                printf("Error: overlapping address ranges, devices: %s and %s, ranges are: [0x%X:0x%X] and 0x%X\n",
                       ranges[i].device_name, device_name, ranges[i].start_address, ranges[i].end_address, addr_range[1]);
                exit(EXIT_FAILURE);
            }
        }
    }
    if(found) {
        return &chip_select[idx];
    }
    printf("Error: Failed to map device %s: too many devices", device_name);
    exit(EXIT_FAILURE);
}

bus_master_iface_t *bus_get_master_iface(void) {
    static bus_master_iface_t iface = {
        .read_data = bus_get_value,
        .write_data = bus_set_value,
        .read_addr = bus_get_addr,
        .write_addr = bus_set_addr,
        .get_direction = bus_get_state,
        .set_direction = bus_set_state,
    };
    return &iface;
}

bus_device_iface_t *bus_get_device_iface(void) {
    static bus_device_iface_t iface = {
        .read_data = bus_get_value,
        .write_data = bus_set_value,
        .read_addr = bus_get_addr,
        // .write_addr = bus_set_addr,
        .get_cs = bus_get_cs,
        .get_direction = bus_get_state,
        // .set_direction = bus_set_state,
    };
    return &iface;
}
