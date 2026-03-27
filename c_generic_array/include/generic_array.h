#ifndef GENERIC_ARRAY_H
#define GENERIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    void* arr;
    size_t e_size;
    size_t capacity;
    size_t size;
} GenericArr;

GenericArr* create_genericArr(size_t e_size,size_t capacity);
void destroy_genericArr(GenericArr* arr);
void generic_arr_push(GenericArr* arr,void* element);
void generic_arr_pop(GenericArr* arr);

#endif