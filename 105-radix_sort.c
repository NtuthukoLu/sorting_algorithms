#include "sort.h"

/**
 * max_value - max value
 *
 * @array: array of integers greater than or equal to 0
 * @size: size of input array
 * Return: maximum value
 */
int max_value(int *array, int size)
{
	int i = 1;
	int iMax = array[0];

	while (i < size)
	{
		if (array[i] > iMax)
			iMax = array[i];
		i++;
	}
	return (iMax);
}

/**
 * count_sort - sorts input array `in_array` of length `in_size`
 *
 * @in_array: array of integers to be sorted
 * @in_size: length of array to be sorted
 * @place: significant digit to sort by
 * Return: sorted array
 */
void count_sort(int *in_array, int in_size, int place)
{
	int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int *result = malloc(sizeof(int) * (in_size));
	int i = 0;

	while (i < in_size)
	{
		count[(in_array[i] / place) % 10]++;
		i++;
	}

	i = 1;
	while (i < 10)
	{
		count[i] += count[i - 1];
		i++;
	}

	for (i = in_size - 1; i >= 0; i--)
	{
		result[count[(in_array[i] / place) % 10] - 1] = in_array[i];
		count[(in_array[i] / place) % 10]--;
	}

	for (i = 0; i < in_size; i++)
		in_array[i] = result[i];

	free(result);
}

/**
 * radix_sort - sorts array in ascending
 * order.
 *
 * @array: array of integers greater than or equal to 0
 * @size: size of input array
 */
void radix_sort(int *array, size_t size)
{
	int iMax;
	int place;

	if (size <= 1 || array == NULL)
		return;

	iMax = max_value(array, size);
	place = 1;
	while (iMax / place > 0)
	{
		count_sort(array, size, place);
		print_array(array, size);

		place *= 10;
	}
}
