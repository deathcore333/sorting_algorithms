#include "sort.h"

/**
 * swap_ints - a function that swaps integers
 * @a: first integer
 * @b: second integers
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*b = *a;
	*b = tmp;
}

/**
 * bitonic_merge - sort a bitonic sequence inside an array of ints
 * @array: array of ints
 * @size: size of array
 * @start: starting index of the sequence in array
 * @seq: size of the sequence to sort
 * @flow: the direction to sort the bitonic sequence blocks
 */

void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			(flow == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - convert an array of ints into bitonic sequence
 * @array: an array of ints
 * @size: array size
 * @start: starting index of the bitonic sequence building block
 * @seq: size of the building block of the bitonic sequence
 * @flow: the direction to sort the bitonic sequence block
 */

void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - sort an array of ints in ascending order using the bitonic
 *		sort algorithm
 * @array: an array of integers
 * @size: the size of the array
 *
 * Description: prints the array after each swap.
 *		only works for size = 2^k where k >= 0
 *		(ie. size equal to powers of 2)
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
