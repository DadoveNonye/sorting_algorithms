#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * bubble_sort - Func that sorts an array of
 * integers in ascending order.
 * @array: Array of integers to sort.
 * @size: The size of the array to be swapped.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size) {
    size_t i, j, k;
    int swapped;

    for (i = 0; i < size - 1; i++) {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                swapped = 1;
                
                /* Print array after each swap */
                for (k = 0; k < size; k++) {
                    printf("%d", array[k]);
                    if (k != size - 1) printf(", ");
                }
                printf("\n");
            }
        }
        
        /* If no two elements were swapped, array is sorted */
        if (swapped == 0)
            break;
    }
}
