#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 *
 * Description: This function swaps two integers within an array.
 */
void swap_ints(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme for quicksort.
 * @array: The array of integers to be partitioned.
 * @size: The size of the array.
 * @left: The starting index of the subset to partition.
 * @right: The ending index of the subset to partition.
 *
 * Return: The final partition index.
 *
 * Description: Partitions a subset of the array based on the Lomuto scheme.
 *              The pivot is the last element of the partition being sorted.
 */
int lomuto_partition(int *array, size_t size, int left, int right) {
    int *pivot = array + right;
    int above = left;
    int below;
    for (below = left; below < right; below++) {
        if (array[below] < *pivot) {
            if (above < below) {
                swap_ints(array + below, array + above);
                print_array(array, size);
            }
            above++;
        }
    }

    if (array[above] > *pivot) {
        swap_ints(array + above, pivot);
        print_array(array, size);
    }

    return above;
}

/**
 * lomuto_sort - Recursive function for quicksort using Lomuto scheme.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 * @left: The starting index of the array partition to sort.
 * @right: The ending index of the array partition to sort.
 *
 * Description: Sorts the array in ascending order using the Lomuto scheme
 *              for partitioning.
 */
void lomuto_sort(int *array, size_t size, int left, int right) {
    if (right - left > 0) {
        int part = lomuto_partition(array, size, left, right);
        lomuto_sort(array, size, left, part - 1);
        lomuto_sort(array, size, part + 1, right);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using quicksort.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: Sorts the given array using the quicksort algorithm
 *              and prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size) {
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, size, 0, size - 1);
}

