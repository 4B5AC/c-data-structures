#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float* arr;
    size_t size;
    size_t capacity;
} float_vector;

float_vector* create_float_vector(size_t capacity){
    float_vector* vector = malloc(sizeof(float_vector));
    if(!vector) return NULL;
    float* arr = malloc(sizeof(float)*capacity);
    if(!arr){free(vector);return NULL;}
    vector->arr = arr;
    vector->capacity = capacity;
    vector->size = 0;
    return vector;
}

void destroy_float_vector(float_vector* vector){
    if(!vector) return;
    free(vector->arr);
    free(vector);
}

void float_vector__push(float_vector* vector,float value){
    if(!vector) return;

    if(vector->size>=vector->capacity){
        size_t new_capacity = vector->capacity==0? 1 : vector->capacity*2;
        float* new_arr = realloc(vector->arr,sizeof(float)*new_capacity);
        if(!new_arr) return;
        vector->arr = new_arr;
        vector->capacity = new_capacity;
    }

    vector->arr[vector->size] = value;
    vector->size+=1;
}

void print_float_vector(float_vector* vector){
    if(!vector || vector->size<=0) return;
    for(size_t i = 0;i<vector->size;i++){
        printf("[%zu] : %f\n",i,vector->arr[i]);
    }
}

void vector_float_pop(float_vector* vector){
    if(!vector) return;
    if(vector->size>0){
        vector->size-=1;
    }
}

int vector_empty(float_vector* vector){
    if(!vector) return -1;
    if(vector->size==0) return 1;
    return 0;
}