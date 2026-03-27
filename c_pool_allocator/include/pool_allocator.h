#ifndef POOL_ALLOCATOR_H
#define POOL_ALLOCATOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    size_t block_size;
    size_t block_count;
    void* memory;
    void* free_blocks;
} Pool;

Pool* create_pool(size_t block_size,size_t block_count);
void destroy_pool(Pool* pool);
void* pool_alloc(Pool* pool);
void pool_free(Pool* pool,void* block);

#endif