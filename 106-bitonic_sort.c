#include "sort.h"

void swap_elem(int *first, int *second);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seqn(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_elem - To swap two integers in an array.
 * @first: first integer to swap.
 * @second: second integer to swap.
 */
void swap_elem(int *first, int *second)
{
	int template;

	template = *first;
	*first = *second;
	*second = template;
}

/**
 * bitonic_merge - To sort a bitonic sequence inside an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 * @start: starting index of the sequence in array to sort.
 * @seq: size of the sequence to sort.
 * @flow: direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t a, jump = seq / 2;

	if (seq > 1)
	{
		for (a = start; a < start + jump; a++)
		{
			if ((flow == UP && array[a] > array[a + jump]) ||
			    (flow == DOWN && array[a] < array[a + jump]))
				swap_elem(array + a, array + a + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seqn - To convert an array of integers into a bitonic sequence.
 * @array: array of integers.
 * @size: size of the array.
 * @start: starting index of a block of the building bitonic sequence.
 * @seq: size of a block of the building bitonic sequence.
 * @flow: direction to sort the bitonic sequence block in.
 */
void bitonic_seqn(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seqn(array, size, start, cut, UP);
		bitonic_seqn(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - To sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seqn(array, size, 0, size, UP);
}
