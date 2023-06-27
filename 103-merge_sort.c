#include "sort.h"

/**
 * print_subarray - prints a subarray,given start and end
 *
 * @arr: array containing subarray to print
 * @start: first index to print
 * @end: index to print to
 */
void print_subarray(int *arr, int start, int end)
{
	int i = start;

	while (i < end - 1)
	{
		printf("%d, ", arr[i]);
		i++;
	}
	printf("%d\n", arr[i]);
}

/**
 * merge_sort - sorts array in ascending order
 * using merge sort algorithm
 *
 * @array: array of integers to sort
 * @size: size of array to be sorted
 */
void merge_sort(int *array, size_t size)
{
	int length = (int)size;
	int i;
	int *A = array;
	int *B;

	/* Make a copy of input array A into array B */
	B = malloc(sizeof(int) * length);
	i = 0;

	while (i < length)
	{
		B[i] = A[i];
		i++;
	}

	split(B, A, 0, length);
	free(B);
}

/**
 * split - recursively splits array into trivially sorted, single-member
 * subarrays.
 *
 * @A: first array
 * @B: temporary array
 * @left: left index of subarray
 * @right: right index of subarray
 */
void split(int *A, int *B, int left, int right)
{
	int mid;

	if (right - left <= 1)
		return;

	mid = (left + right) / 2;

	/* recursively split */
	split(B, A, left, mid);
	split(B, A, mid, right);

	/* merge back together */
	merge(A, B, left, mid, right);
	printf("Merging...\n[left]: ");
	print_subarray(A, left, mid);
	printf("[right]: ");
	print_subarray(A, mid, right);
	printf("[Done]: ");
	print_subarray(B, left, right);
}

/**
 * merge - merges two arrays
 *
 * @A: first array to merge
 * @B: second array to merge
 * @left: start of first subarray
 * @mid: start of right subarray
 * @right: end of array
 */
void merge(int *A, int *B, int left, int mid, int right)
{
	int i, aPosition, bPosition;

	aPosition = left;
	bPosition = mid;
	i = left;

	while (i < right)
	{
		if (aPosition < mid && (bPosition >= right || A[aPosition] <= A[bPosition]))
		{
			B[i] = A[aPosition];
			aPosition++;
		}
		else
		{
			B[i] = A[bPosition];
			bPosition++;
		}
		i++;
	}
}
