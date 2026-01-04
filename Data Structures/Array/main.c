#include "stdio.h"
#include "array_utils.h"

int main(void) {
    int array[MAX_SIZE];
    int size = 0;
    int choise, value, position;

    while(1) {
        printf("-------------------------");
        printf("\n1. Print array");
        printf("\n2. Add Value at End");
        printf("\n3. Add Value at Position");
        printf("\nYour choise: ");
        scanf("%d", &choise);
        printf("-------------------------");

        switch (choise) {
            case 1:
                printf("\n");
                print_array(array, size);
                break;
            case 2:
                printf("\nWrite a value to add: "); scanf("%d", &value);
                insert_at_end(array, &size, value);
                break;
            case 3:
                printf("\nWrite a value to add: "); scanf("%d", &value);
                printf("\nWrite a position to write that value: "); scanf("%d", &position);
                insert_at_position(array, &size, value, position - 1);
                break;
            case 0:
                return 0;
            default:
                printf("\nInvalid.\n");
        }
    }
}