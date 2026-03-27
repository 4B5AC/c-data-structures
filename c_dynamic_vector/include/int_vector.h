#ifndef INT_VECTOR_H
#define INT_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    size_t size;
    size_t capacity;
} vector_int;

vector_int* create_int_vector(size_t capacity);
void destroy_int_vector(vector_int* vector);
void int_vector_push(vector_int* vector,int value);
void int_vector_pop(vector_int* vector);
void print_int_vector(vector_int* vector);
int vector_empty(vector_int* vector);

#endif