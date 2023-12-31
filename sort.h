#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure Definition */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*Given Functions*/
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/*Functions methods*/
void bubble_sort(int *array, size_t size);
void array_swap(int *array, int a, int b);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void partition(int *array, int low, int high, size_t size);

void shell_sort(int *array, size_t size);

void cocktail_sort_list(listint_t **list);
void swap_node(listint_t **list, listint_t *node);
listint_t *create_listint(const int *array, size_t size);


void print_subarray(int *arr, int start, int end);
void merge(int *A, int *B, int left, int mid, int right);
void split(int *A, int *B, int left, int right);
void merge_sort(int *array, size_t size);

void heap_sort(int *array, size_t size);
void heapify(int *array, int i, int len, size_t size);

void radix_sort(int *array, size_t size);
void count_sort(int *in_array, int in_size, int place);
int max_value(int *array, int size);

#endif
