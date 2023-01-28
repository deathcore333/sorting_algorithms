#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - a function that swaps two integers in array
 * @a: the first integer
 * @b: the second integer
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	*a = tmp;
	*b = *a;
	*b = tmp;
}

/**
 * hoare_partition - order a subset of an array of integers according
 *			to the hoare partition scheme
 * @array: array of integers
 * @size: size of the array
 * @left: starting index of the subset to order
 * @right: ending index of the subset to order
 *
 * Return: the final partition index
 *
 * Description: uses the last element of the partition as  the pivot
 *		Prints the array after each swap
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - implement the quicksort algo through a recursion
 * @array: array of integers to sort
 * @size: array size
 * @left: starting index of the array partition to order
 * @right: ending index of the array partition
 *
 * Description: Uses the Hoare partition scheme
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - sort an array of ints in ascending order using
 *			the quicksort algorithm
 * @array: array of integers
 * @size: size of the array
 *
 * Description: uses the Hoare partition scheme
 *		prints the array after each swap of two elements
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
