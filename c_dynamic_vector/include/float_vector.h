#ifndef FLOAT_VECTOR_H
#define FLOAT_VECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float* arr;
    size_t size;
    size_t capacity;
} float_vector;

float_vector* create_float_vector(size_t capacity);
void destroy_float_vector(float_vector* vector);
void float_vector_push(float_vector* vector,float value);
void float_vector_pop(float_vector* vector);
void print_float_vector(float_vector* vector);
int vector_empty(float_vector* vector);

#endif