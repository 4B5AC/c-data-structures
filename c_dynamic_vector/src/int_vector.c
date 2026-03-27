#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    size_t size;
    size_t capacity;
} int_vector;

int_vector* create_int_vector(size_t capacity){
    int_vector* vector = malloc(sizeof(int_vector));
    if(!vector) return NULL;
    int* arr = malloc(sizeof(int)*capacity);
    if(!arr){free(vector);return NULL;}
    vector->arr = arr;
    vector->capacity = capacity;
    vector->size = 0;
    return vector;
}

void destroy_int_vector(int_vector* vector){
    if(!vector) return;
    free(vector->arr);
    free(vector);
}

void int_vector_push(int_vector* vector,int value){
    if(!vector) return;

    if(vector->size>=vector->capacity){
        size_t new_capacity = vector->capacity==0? 1 : vector->capacity*2;
        int* new_arr = realloc(vector->arr,sizeof(int)*new_capacity);
        if(!new_arr) return;
        vector->arr = new_arr;
        vector->capacity = new_capacity;
    }

    vector->arr[vector->size] = value;
    vector->size+=1;
}

void print_int_vector(int_vector* vector){
    if(!vector || vector->size<=0) return;
    for(size_t i = 0;i<vector->size;i++){
        printf("[%zu] : %d\n",i,vector->arr[i]);
    }
}

void int_vector_pop(int_vector* vector){
    if(!vector) return;
    if(vector->size>0){
        vector->size-=1;
    }
}

int vector_empty(int_vector* vector){
    if(!vector) return -1;
    if(vector->size==0) return 1;
    return 0;
}