#include <stdio.h>
#include "array_utils.h"

void print_array(int arr[], int size) {
    if(size == 0) return;

    printf("[ ");
    for(int i = 0; i < size; i++) {
        printf("%d - ", arr[i]);
    }
    printf("]\n");
}

void insert_at_end(int arr[], int *size, int value) {
    if(*size == MAX_SIZE) {
        printf("Error: Array FULL\n");
        return;
    }
    arr[*size] = value;
    (*size)++;
}

void insert_at_position(int arr[], int *size, int value, int position) {
    if(*size == MAX_SIZE) {
        printf("Error: Array FULL\n");
        return;
    }
    if(position < 0 || *size < position) return;
    for(int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*size)++;
}