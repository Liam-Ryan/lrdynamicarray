#include "lrdynamicarray.h"

#include <stdio.h>
#include <stdbool.h>

int32_t lrdynamicarray_init(lrdynamicarray **arr, uint32_t initialCapacity) {

    if (*arr == NULL)
        return -1;

    (*arr)->currentSize = 0;
    (*arr)->capacity = initialCapacity;
    (*arr)->internalArray = malloc(sizeof(void *) * initialCapacity);
    void **intArray = (*arr)->internalArray;


    if (intArray == NULL)
        return -1;

    for (uint32_t i = 0; i < initialCapacity; i++) {
        intArray[i] = NULL;
    }
    return 0;

};

bool ensureCapacity(lrdynamicarray **arr, uint32_t index) {
    if (*arr == NULL)
        return false;

    if (index < (*arr)->capacity)
        return true;

    (*arr)->capacity = (*arr)->capacity * 2;
    realloc((*arr)->internalArray, sizeof(void *) * (*arr)->capacity * 2);

    if ((*arr)->internalArray == NULL)
        return false;

    for (uint32_t i = index; i < (*arr)->capacity; i++) {
        (*arr)->internalArray[i] = NULL;
    }
    return true;
}

int32_t lrdynamicarray_insert(lrdynamicarray **arr, uint32_t position, void *element) {
    if (ensureCapacity(arr, position)) {
        (*arr)->internalArray[position] = element;
        if (position >= (*arr)->currentSize) {
            (*arr)->currentSize = position + 1;
        }
        return position;
    }
    return -1;
};


int32_t lrdynamicarray_push(lrdynamicarray **arr, void *element) {
    if(arr != NULL && *arr != NULL)
        return lrdynamicarray_insert(arr, (*arr)->currentSize, element);
    return -1;
};

void *lrdynamicarray_get(lrdynamicarray *arr, uint32_t position) {
    if (arr != NULL) {
        if (position >= arr->currentSize) {
            return NULL;
        }
        return arr->internalArray[position];
    }
};

uint32_t lrdynamicarray_size(lrdynamicarray *arr) {
    if (arr != NULL)
        return arr->currentSize;
    return 0;
};