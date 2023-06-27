#include "sort.h"

/**
 * merge_sort - sorts array in ascending order
 * using merge sort algorithm
 *
 * @array: array of integers to sort
 * @size: size of array to be sorted
 */
void merge_sort(int *array, size_t size)
{
	int length = (int)size, i;
	int *A = array, *B;

	/* Make a copy of input array A into array B */
	B = malloc(sizeof(int) * length);
	for (i = 0; i < length; i++)
		B[i] = A[i];

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
	int middle;

	if (right - left <= 1)
		return;

	middle = (left + right) / 2;

	/* recursively split */
	split(B, A, left, middle);
	split(B, A, mid, right);

	/* merge back together */
	merge(A, B, left, middle, right);

	printf("Merging...\n[left]: ");
	print_subarray(A, left, middle);
	printf("[right]: ");
	print_subarray(A, middle, right);
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
		if (aPos < mid && (bPos >= right || A[aPos] <= A[bPos]))
		{
			B[i] = A[aPos];
			aPos++;
		}
		else
		{
			B[i] = A[bPos];
			bPos++;
		}
		i++;
	}
}

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

	while ( i < end - 1)
	{
		printf("%d, ", arr[i]);
		i++;
	}
	printf("%d\n", arr[i]);
}
