#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"

// Helper function
// static
static void ensure_array(DynamicArray *arr) {
    int newCapacity = arr->capacity * 2;
    int *newData = (int*)realloc(arr->data, newCapacity * sizeof(int*));

    if(!newData){
        printf("Critical Error: Memory Reallocation Failed.\n");
        return;
    }

    arr->capacity = newCapacity;
    arr->data = newData;
}

// non static
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

// Array functions
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
    // ensure the array capacity
    if(arr->size == arr->capacity) {
        ensure_array(arr);
    }

    arr->data[arr->size] = value;
    (arr->size)++;
}

void insert_at_position(DynamicArray *arr, int value, int position) {
    // if its the last position, call the function insert at end
    if(position == arr->size + 1) {
        insert_at_end(arr, value);
        return;
    }

    // verification valid position
    if(position < 0 || position > arr->size) {
        printf("Invalid position.\n");   
        return;
    }
    
    // ensure the array capacity
    if(arr->size == arr->capacity) {
        ensure_array(arr);
    }

    /**
    * Shift elements to the right to create a gap at 'position'.
    * Use memmove instead of memcpy or a manual loop for O(n) efficiency and 
    * to safely handle overlapping memory regions.
    * * Destination: &arr->data[position + 1]
    * Source:      &arr->data[position]
    * Size:        Remaining elements * sizeof(int)
    */
    if(position < arr->size) {    
        memmove(&arr->data[position + 1], &arr->data[position], (arr->size - position) * sizeof(int));
    }

    arr->data[position] = value;
    arr->size++;
}

void delete_at_position(DynamicArray *arr,  int position) {
    // verification valid position
    if(position < 0 || position > arr->size) {
        printf("Invalid position.\n");
        return;
    }

    /**
    * Shift elements to the left to close the gap at 'position'.
    * Overwrites the element at 'position' with subsequent elements.
    * Safe for overlapping regions within the Heap block.
    * Complexity: O(n)
    */
    if(position < arr->size) {
        memmove(&arr->data[position], &arr->data[position + 1], (arr->size - position - 1) * sizeof(int));
    }

    arr->size--;

    arr->data[arr->size] = 0;

    // reduce the arr->capacity if its / 4 of the full capacity
    if(arr->size > 0 && arr->size >= arr->capacity / 4) {
        int newCapacity = arr->capacity / 2;
        int *temp = realloc(arr->data, newCapacity * sizeof(int));
        if(temp) {
            arr->data = temp;
            arr->capacity = newCapacity;
        }
    }
}

void delete_array(DynamicArray *arr) {
    free(arr->data);
    free(arr);
    printf("\nArray Sucessfully Deleted and Free\n");
}