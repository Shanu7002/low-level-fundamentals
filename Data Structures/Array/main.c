#include "stdio.h"
#include "array_utils.h"

int main(void) {
    int array[MAX_SIZE];
    int size = 0;
    int choise;

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
                print_array(array, size);
        }
    }
}