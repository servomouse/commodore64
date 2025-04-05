#include <stdio.h>
#include "memory.h"

static uint32_t get_file_size(FILE *file) {
    uint32_t init_location = ftell(file);
    fseek(file, 0, SEEK_END);
    uint32_t file_size = ftell(file);
    fseek(file, init_location, SEEK_SET);
    return file_size;
}

void memory_map_file(char *filename, memory_t *memory, uint32_t offset) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("MEMORY ERROR: Failed to open file %s\n", filename);
        exit(1);
    }
    if (memory->size < get_file_size(file)) {  // Check file size
        printf("MEMORY ERROR: File %s is too large!", filename);
        exit(1);
    }
    uint8_t *ptr = &memory->arr[offset];
    size_t bytes_read = 0;
    while((bytes_read = fread(ptr, 1, 1, file)) > 0) {
        ptr++;
    }
    fclose(file);
}

memory_t *memory_init(uint32_t memory_size, uint8_t memory_type) {
    memory_t *memory = calloc(sizeof(memory_t) + memory_size, 1);
    if(memory == NULL) {
        printf("Error: cannot allocate memory!");
        exit(1);
    }
    memory->size = memory_size;
    memory->type = memory_type;
    return memory;
}
