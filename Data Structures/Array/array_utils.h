#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* create_array(int initial_capacity);
void print_array(DynamicArray *arr);
void insert_at_end(DynamicArray *arr, int value);
void insert_at_position(DynamicArray *arr, int value, int position);
void delete_at_position(DynamicArray *arr, int position);

#endif