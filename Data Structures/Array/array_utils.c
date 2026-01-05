#include <stdio.h>
#include "array_utils.h"

void print_array(int arr[], int size) {
    // print empty array if array is empty
    if(size == 0) {
        printf("[ ]");
        return;
    }

    printf("[ ");
    for(int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        // slash only if isnt the last number
        if(i < size - 1){
            printf(" - ");
        }
    }
    printf(" ]\n");
}

void insert_at_end(int arr[], int *size, int value) {
    // verification for prevent buffer overflow
    if(*size == MAX_SIZE) {
        printf("Error: Array FULL\n");
        return;
    }
    arr[*size] = value;
    (*size)++;
}

void insert_at_position(int arr[], int *size, int value, int position) {
    // verification for prevent buffer overflow
    if(*size == MAX_SIZE) {
        printf("Error: Array FULL\n");
        return;
    }
    // verification valid position
    if(position < 0 || position > *size) {
        printf("Invalid position.\n");   
        return;
    }
    // move all number one index to right and add the new one
    for(int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*size)++;
}

void delete_at_position(int arr[], int *size, int position) {
    if(position < 0 || position > *size) {
        printf("Invalid position.\n");
        return;
    }

    for(int i = position; i < *size; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}