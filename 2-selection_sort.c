#include "sort.h"

/**
 * swap_elem - To swap two integers in an array.
 * @first: First integer to be swapped.
 * @second: Second integer to be swapped.
 */
void swap_elem(int *first, int *second)
{
	int template;

	template = *first;
	*first = *second;
	*second = template;
}

/**
 * selection_sort - To sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: Array of elements.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	int *least;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		least = array + a;
		for (b = a + 1; b < size; b++)
			least = (array[b] < *least) ? (array + b) : least;

		if ((array + a) != least)
		{
			swap_elem(array + a, least);
			print_array(array, size);
		}
	}
}
