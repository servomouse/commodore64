#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef __unix__
    #define DLL_PREFIX 
#elif defined(_WIN32) || defined(WIN32)
    #define DLL_PREFIX __declspec(dllexport)
#endif

#define sizeof_arr(_x) sizeof(_x)/sizeof(_x[0])

#define READ_FUNC_PTR(_func_name)  uint32_t(*_func_name)(uint32_t, uint32_t)
#define WRITE_FUNC_PTR(_func_name) void(*_func_name)(uint32_t, uint32_t, uint32_t)

int store_data(void *data, size_t size, char *filename);
void *restore_data(char *filename, uint32_t *data_size);
