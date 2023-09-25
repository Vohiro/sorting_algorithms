#include "sort.h"

/**
 * get_highest - Get the highest value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The highest integer in the array.
 */
int get_max(int *array, int size)
{
	int highest, a;

	for (highest = array[0], a = 1; a < size; a++)
	{
		if (array[a] > highest)
			highest = array[a];
	}

	return (highest);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, highest, a;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	highest = get_highest(array, size);
	count = malloc(sizeof(int) * (highest + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (a = 0; a < (highest + 1); a++)
		count[a] = 0;
	for (a = 0; a < (int)size; a++)
		count[array[a]] += 1;
	for (a = 0; a < (highest + 1); a++)
		count[a] += count[a - 1];
	print_array(count, highest + 1);

	for (a = 0; a < (int)size; a++)
	{
		sorted[count[array[a]] - 1] = array[a];
		count[array[a]] -= 1;
	}

	for (a = 0; a < (int)size; a++)
		array[a] = sorted[a];

	free(sorted);
	free(count);
}
