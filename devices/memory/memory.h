#pragma once

#include <stdint.h>
#include <stdlib.h>

typedef struct {
    uint32_t size;
    uint8_t type;
    uint8_t arr[0];
} memory_t;

// Create memory of mem_size bytes, and upload an image (optional)
// memory_type: 0: ROM, 1: RAM
memory_t *memory_init(uint32_t memory_size, uint8_t memory_type);
