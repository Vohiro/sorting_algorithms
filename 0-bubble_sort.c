#include "sort.h"

/**
 * swap_elem - To swap two elements in an array.
 * @first: The first element to be swapped.
 * @second: The second element to swapped.
 */
void swap_elem(int *first, int *second)
{
	int template;

	template = *first;
	*first = *second;
	*second = template;
}

/**
 * bubble_sort - To sort an array of integers in ascending order.
 * @array: An array of integers to be sorted.
 * @size: The size of the array to be sorted.
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, length = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (a = 0; a < length - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				swap_elem(array + a, array + a + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		length--;
	}
}
