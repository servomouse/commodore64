#include  <time.h>
#include <string.h>
#include "utils.h"
#include <math.h>

uint64_t get_hash(uint8_t *data, size_t size) {
    uint64_t hash = 5381;
    for(size_t i=0; i<size; i++) {
        hash = ((hash << 5) + hash) + data[i];
    }
    return hash;
}

typedef struct {
    uint32_t size;  // bytes
    uint64_t hash;
    uint8_t data[0];
} stored_data_t;

int store_data(void *data, size_t size, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("ERROR: Failed to open file %s\n", filename);
        return EXIT_FAILURE;
    }
    stored_data_t data_struct = {
        .size = size,
        .hash = get_hash((uint8_t*)data, size)
    };
    fwrite(&data_struct, sizeof(stored_data_t), 1, file);
    fwrite((uint8_t *)data, 1, size, file);
    fclose(file);
    return EXIT_SUCCESS;
}

// Free the returned pointer after use
void *restore_data(char *filename, uint32_t *data_size) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("ERROR: Failed to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    stored_data_t data_struct = {0};
    fread((uint8_t *)&data_struct, sizeof(stored_data_t), 1, file);
    if(data_size != NULL) {
        *data_size = data_struct.size;
    }
    uint8_t *data = calloc(data_struct.size, 1);
    size_t len_data = fread((uint8_t *)data, 1, data_struct.size, file);
    if(data_struct.hash != get_hash((uint8_t*)data, data_struct.size)) {
        printf("ERROR: File %s corrupted (hash check failed)\n", filename);
        exit(EXIT_FAILURE);
    }
    fclose(file);
    if(len_data != data_struct.size) {
        printf("ERROR: Failed reading file %s (%lld of %d bytes were read)\n", filename, len_data, data_struct.size);
        exit(EXIT_FAILURE);
    }
    return data;
}
