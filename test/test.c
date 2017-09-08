#include <stdio.h>
#include <inttypes.h>
#include "lrdynamicarray.h"

int main() {
    lrdynamicarray *arr = malloc(sizeof(lrdynamicarray));
    lrdynamicarray_init(&arr, 1);
    lrdynamicarray_insert(&arr, 0, (void *) 0);
    lrdynamicarray_insert(&arr, 1, (void *) 1);
    lrdynamicarray_insert(&arr, 2, (void *) 2);
    lrdynamicarray_push(&arr, (void *) 3);
    fprintf(stdout, "\nArray contains %" PRIu32 " elements.", lrdynamicarray_size(arr));
    for(uint32_t i = 0; i < arr->currentSize; i++ ) {
        fprintf(stdout, "\nArray element %" PRIu32 " is %" PRIu32 ".", i, (uint32_t) lrdynamicarray_get(arr, i));
    }
}
