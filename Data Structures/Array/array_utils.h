#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#define MAX_SIZE 100

void print_array(int arr[], int size);
void insert_at_end(int arr[], int *size, int value);
void insert_at_position(int arr[], int *size, int value, int position);
void delete_at_position(int arr[], int *size, int position);

#endif