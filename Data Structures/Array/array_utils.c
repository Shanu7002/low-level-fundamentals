#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"

DynamicArray* create_array(int initial_capacity) {
    DynamicArray *arr =(DynamicArray*)malloc(sizeof(DynamicArray));
    if (!arr) return NULL;

    arr->data = (int*)malloc(initial_capacity * sizeof(int));
    if (!arr->data) {
        free(arr);
        return NULL;
    }

    arr->size = 0;
    arr->capacity = initial_capacity;
    return arr;
}

void print_array(DynamicArray *arr) {
    // print empty array if array is empty
    if(arr->size == 0) {
        printf("[ ]\n");
        return;
    }

    printf("[ ");
    for(int i = 0; i < arr->size; i++) {
        printf("%d%s", arr->data[i], (i < arr->size - 1) ? " - " : "");
        
    }
    printf(" ]\n");
    printf("(Size: %d, Cap: %d)\n", arr->size, arr->capacity);
}

void insert_at_end(DynamicArray *arr, int value) {
    if(arr->size == arr->capacity) {
        int newCapacity = arr->capacity * 2;
        int *newData = (int*)realloc(arr->data, newCapacity * sizeof(int));
        
        if(!newData) {
            printf("Critical Error: Memory reallocation failed\n");
            return;
        }
        arr->data = newData;
        arr->capacity = newCapacity;
    }

    arr->data[arr->size] = value;
    (arr->size)++;
}

void insert_at_position(DynamicArray *arr, int value, int position) {
    if(position == arr->size + 1) {
        insert_at_end(arr, value);
        return;
    }
    // verification valid position
    if(position < 0 || position > arr->size) {
        printf("Invalid position.\n");   
        return;
    }
    // move all number one index to right and add the new one
    if(arr->size == arr->capacity) {
        int newCapacity = arr->capacity * 2;
        int *newData = (int*)realloc(arr->data, newCapacity * sizeof(int));

        if(!newData) {
            printf("Critical Error: Memory Reallocation Failed.");
            return;
        }

        arr->data = newData;
        arr->capacity = newCapacity;
    }

    for(int i = arr->size; i > position; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[position] = value;
    arr->size++;
}

void delete_at_position(DynamicArray *arr,  int position) {
    if(position < 0 || position > arr->size) {
        printf("Invalid position.\n");
        return;
    }

    for(int i = position; i < arr->size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    arr->size--;

    arr->data[arr->size] = 0;
}

void delete_array(DynamicArray *arr) {
    if(arr) {
        free(arr->data);
        free(arr);
        printf("Array Sucessfully Deleted and Free");
    }
    printf("Empty array cannot be deleted.");
}