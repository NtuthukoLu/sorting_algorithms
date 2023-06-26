#include "sort.h"
/**
 * array_swap - swaps two integers in an array
 * @array: array to be sorted
 * @a: index of first integer
 * @b: index of second integer
 *
 * Return: Void
 */

void array_swap(int *array, int a, int b)
{
	int tempo;

	tempo = array[a];
	array[a] = array[b];
	array[b] = tempo;
}

/**
 * bubble_sort - sort int array in ascending order using bubble sort
 * @array: array to sort
 * @size: number of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, newnumber, tempo;

	if (size < 2)
		return;

	while (tempo >= 1)
	{
		newnumber = 0;
		i = 1;
		while (i < size)
		{
			if (array[i - 1] > array[i])
			{
				array_swap(array, i - 1, i);
				newnumber = i;
				print_array(array, size);
			}
			i++;
		}
		tempo = newnumber;
	}
}
