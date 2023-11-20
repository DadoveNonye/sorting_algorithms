#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @head: Pointer to the head of the list.
 * @node1: Pointer to the first node to swap.
 * @node2: Pointer to the second node to swap.
 */
void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2) {
    if (node1->prev != NULL)
        node1->prev->next = node2;
    else
        *head = node2;

    if (node2->next != NULL)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                        using the insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list) {

    listint_t *iter, *insert, *tmp;
    listint_t **head = list;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    for (iter = (*list)->next; iter != NULL; iter = tmp) {
        tmp = iter->next;
        insert = iter->prev;

        while (insert != NULL && iter->n < insert->n) {
            swap_nodes(head, insert, iter);
            print_list((const listint_t *)*head);
            insert = iter->prev;
        }
    }
}
