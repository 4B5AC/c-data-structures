#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    void* arr;
    size_t e_size;
    size_t capacity;
    size_t size;
} GenericArr;

GenericArr* create_genericArr(size_t e_size,size_t capacity){
    GenericArr* g_arr = malloc(sizeof(GenericArr));
    if(!g_arr) return NULL;
    void* arr = malloc(e_size*capacity);
    if(!arr){free(g_arr);return NULL;}
    g_arr->arr = arr;
    g_arr->capacity = capacity;
    g_arr->e_size = e_size;
    g_arr->size = 0;
    return g_arr;
}

void destroy_genericArr(GenericArr* arr){
    if(!arr) return;
    free(arr->arr);
    free(arr);
}

void generic_arr_push(GenericArr* arr,void* element){
    if(!arr || !element) return;
    if(arr->size>=arr->capacity){
        size_t new_capacity = arr->capacity==0? 1 : arr->capacity * 2;
        void* new_arr = realloc(arr->arr,arr->e_size*new_capacity);
        if(!new_arr) return;
        arr->arr = new_arr;
        arr->capacity = new_capacity;
    }

    char* dest = (char*)arr->arr + arr->size*arr->e_size;
    memcpy(dest,element,arr->e_size);
    arr->size+=1;
}

void generic_arr_pop(GenericArr* arr){
    if(!arr || arr->size==0) return;
    arr->size -= 1;
}