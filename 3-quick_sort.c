#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two elements in an array.
 * @a: First element.
 * @b: Second element.
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Partitions the array using Lomuto partition scheme.
 * @array: Array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 *
 * Return: Index of the pivot element after partitioning.
 */
int lomuto_partition(int *array, int low, int high, size_t size) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
            /* Printing the array after each swap */
            for (size_t k = 0; k < size; k++) {
                printf("%d", array[k]);
                if (k != size - 1) {
                    printf(", ");
                } else {
                    printf("\n");
                }
            }
        }
    }
    swap(&array[i + 1], &array[high]);
    /* Printing the array after each swap */
    for (size_t k = 0; k < size; k++) {
        printf("%d", array[k]);
        if (k != size - 1) {
            printf(", ");
        } else {
            printf("\n");
        }
    }
    return i + 1;
}

/**
 * quicksort - Implements the Quick sort algorithm.
 * @array: Array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 */
void quicksort(int *array, int low, int high, size_t size) {
    if (low < high) {
        int pi = lomuto_partition(array, low, high, size);
        quicksort(array, low, pi - 1, size);
        quicksort(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size) {
    if (array == NULL || size < 2) {
        return;
    }
    quicksort(array, 0, size - 1, size);
}
