#include "sort.h"

/**
 * swap_elem - To swap two elements in an array.
 * @first: first integer to be swapped.
 * @second: second integer to be swapped.
 */
void swap_elem(int *first, int *second)
{
	int template;

	template = *first;
	*first = *second;
	*second = template;
}

/**
 * shell_sort - To sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Sequqence: to use the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gp, i, j;

	if (array == NULL || size < 2)
		return;

	for (gp = 1; gp < (size / 3);)
		gp = gp * 3 + 1;

	for (; gp >= 1; gp /= 3)
	{
		for (i = gp; i < size; i++)
		{
			j = i;
			while (j >= gp && array[j - gp] > array[j])
			{
				swap_elem(array + j, array + (j - gp));
				j -= gp;
			}
		}
		print_array(array, size);
	}
}
