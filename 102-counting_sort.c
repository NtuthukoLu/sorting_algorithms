#include "sort.h"

/**
 * counting_sort - counting sort algo
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int max = array[0];
	size_t index = 0;
    int *count = malloc((max + 1) * sizeof(int));

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create a counting array of size max + 1 and initialize all elements to 0 */
	if (count == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}
	for (int i = 0; i <= max; i++)
	{
		count[i] = 0;
	}

	/* Count the occurrences of each element in the array */
	for (size_t i = 0; i < size; i++)
	{
		count[array[i]]++;
	}

	/* Print the counting array */
	for (int i = 0; i <= max; i++)
	{
		printf("%d, ", count[i]);
	} printf("\n");

	/* Update the array with the sorted elements */
	for (int i = 0; i <= max; i++)
	{
		while (count[i] > 0)
		{
			array[index++] = i;
			count[i]--;
		}
	} free(count);
}