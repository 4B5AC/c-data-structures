#include <stdio.h>
#include <stdlib.h>

typedef struct {
    size_t block_size;
    size_t block_count;
    void* memory;
    void* free_blocks;
} Pool;

Pool* create_pool(size_t block_size,size_t block_count){
    Pool* pool = malloc(sizeof(Pool));
    if(!pool) return NULL;
    void* memory = malloc(block_size*block_count);
    if(!memory){free(pool);return NULL;}
    pool->memory = memory;
    pool->block_count = block_count;
    pool->block_size = block_size;
    pool->free_blocks = memory;

    char* ptr = (char*)memory;
    for(size_t i=0;i<block_count-1;i++){
        *(void**)ptr = ptr+block_size;
        ptr+=block_size;
    }*(void**)ptr = NULL;

    return pool;
}

void destroy_pool(Pool* pool){
    if(!pool) return;
    free(pool->memory);
    free(pool);
}

void* pool_alloc(Pool* pool){
    if(!pool) return NULL;
    void* head = pool->free_blocks;
    pool->free_blocks = *(void**)head;
    return head;
}

void pool_free(Pool* pool,void* block){
    if(!pool || !block) return;
    *(void**)block = pool->free_blocks;
    pool->free_blocks = block;
}