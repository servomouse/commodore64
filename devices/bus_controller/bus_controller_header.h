#pragma once

#include <stdint.h>

typedef struct {
    uint32_t(*read_data)(void);         // Read data from the data bus
    void(*write_data)(uint32_t);        // Write data to the data bus
    uint32_t(*read_addr)(void);         // Read address from the address bus
    // void(*write_addr)(uint32_t);        // Write address to the address bus
    uint8_t(*get_cs)(uint32_t);         // Get Chip Select by index
    uint8_t(*get_direction)(void);      // Get R/W state
    // void(*set_direction)(uint8_t);     // Set R/W state
} bus_device_iface_t;

typedef struct {
    uint32_t(*read_data)(void);         // Read data from the data bus
    void(*write_data)(uint32_t);        // Write data to the data bus
    uint32_t(*read_addr)(void);         // Read address from the address bus
    void(*write_addr)(uint32_t);        // Write address to the address bus
    // uint8_t(*get_cs)(uint32_t);         // Get Chip Select by index
    uint8_t(*get_direction)(void);      // Get R/W direction
    void(*set_direction)(uint8_t);      // Set R/W direction
    uint8_t(*get_state)(void);          // Get BUSY/FREE state
    void(*set_state)(uint8_t);          // Set BUSY/FREE state
} bus_master_iface_t;
