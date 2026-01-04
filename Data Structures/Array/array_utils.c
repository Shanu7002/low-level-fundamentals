#include <stdio.h>
#include "array_utils.h"

void print_array(int arr[], int size) {
    if(size == 0) return;

    printf("[ ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}