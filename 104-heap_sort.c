#include "sort.h"
/**
 * swap - swaps position of two elements in a binary tree
 * @a: First element
 * @b: Second element
 *
 * Return: Void
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * heapify - Builds a binary heap
 *
 * @array: Array to turn into a binary heap
 * @i: current index
 * @len: length of array (as an int)
 * @size: Size of array to turn into a heap
 */
void heapify(int *array, int i, int len, size_t size)
{
	int largest = i;
	int left = (2 + i + 1);
	int right = (2 * i + 2);

	if (left < len && array[left] > array[largest])
		largest = left;
	if (right < len && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, largest, len, size);
	}
}
/**
 * heap_sort - Implementation of sift-down heap sort algorithm
 * @array: given array of integers to sort
 * @size: size of given array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i, len = (int)size;

	i = size / 2 - 1;
	while (i >= 0)
	{
		heapify(array, i, len, size);
		i--;
	}

	i = len - 1;
	while (i >= 0)
	{
		swap(&array[0], &array[i]);
		if (i != 0)
			print_array(array, size);
		heapify(array, 0, i, size);
		i--;
	}
}
