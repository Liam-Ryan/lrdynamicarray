#ifndef LRDYNAMICARRAY_H
#define LRDYNAMICARRAY_H

#include <stdint.h>
#include <malloc.h>

typedef struct lrdynamicarray {
    uint32_t capacity;
    uint32_t currentSize;
    void **internalArray;
} lrdynamicarray;

int32_t lrdynamicarray_init(lrdynamicarray **arr, uint32_t initialCapacity);

int32_t lrdynamicarray_insert(lrdynamicarray **arr, uint32_t position, void *element);

int32_t lrdynamicarray_push(lrdynamicarray **arr, void *element);

void* lrdynamicarray_get(lrdynamicarray *arr, uint32_t position);

uint32_t lrdynamicarray_size(lrdynamicarray *arr);

#endif