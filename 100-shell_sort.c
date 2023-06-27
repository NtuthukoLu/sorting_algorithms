#include "sort.h"
/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	int i, j, k, temp;
	int interval = 1;

	while (interval <= (int)size / 3)
	{
		interval = interval * 3 + 1;
	}
	while (interval > 0)
	{
		for (i = interval; i < (int)size; i++)
		{
			temp = array[i];
			j = i;
			while (j > interval - 1 && array[j - interval] >= temp)
			{
				array[j] = array[j - interval];
				j = j - interval;
			}
			array[j] = temp;
		}
		interval = (interval - 1) / 3;
	}
	for (k = 0; k < (int)size; k++)
	{
		printf("%d, ",array[k]);
	}
	printf("\n");
}
