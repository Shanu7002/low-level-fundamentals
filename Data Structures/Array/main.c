#include <stdio.h>
#include "array_utils.h"

int main(void) {
    DynamicArray *arr = create_array(2);

    if(arr == NULL) {
        printf("Error in memory allocation");
        return 1;
    }
    
    int choise, value, position;

    // repeat until user type 0
    while(1) {
        printf("-------------------------");
        printf("\n1. Print array");
        printf("\n2. Add Value at End");
        printf("\n3. Add Value at Position");
        printf("\n4. Remove at Position");
        printf("\n0. Exit and Free Memory");
        printf("\nYour choise: ");
        scanf("%d", &choise);
        printf("-------------------------");

        switch (choise) {
            case 1:
                printf("\n");
                print_array(arr);
                break;
            case 2:
                printf("\nWrite a value to add: "); scanf("%d", &value);
                insert_at_end(arr, value);
                break;
            case 3:
                printf("\nWrite a value to add: "); scanf("%d", &value);
                printf("\nWrite a position to write that value: "); scanf("%d", &position);
                insert_at_position(arr, value, position - 1); // -1 for index human friendly
                break;
            case 4:
                printf("\nSelect a position to delete: "); scanf("%d", &position);
                delete_at_position(arr, position - 1); // -1 for index human friendly
                break;
            case 0:
                return 0;
            default:
                printf("\nInvalid.\n");
        }
    }
}