#include "sort.h"

int get_highest(int *array, int size);
void radix_counting_sort(int *array, size_t size, int signf, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_highest - To get the highest value in an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Return: highest integer in the array.
 */
int get_highest(int *array, int size)
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
 * radix_counting_sort - To sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 * @signf: significant digit to sort on.
 * @buff: buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int signf, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t a;

	for (a = 0; a < size; a++)
		count[(array[a] / signf) % 10] += 1;

	for (a = 0; a < 10; a++)
		count[a] += count[a - 1];

	for (a = size - 1; (int)a >= 0; a--)
	{
		buff[count[(array[a] / signf) % 10] - 1] = array[a];
		count[(array[a] / signf) % 10] -= 1;
	}

	for (a = 0; a < size; a++)
		array[a] = buff[a];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int highest, signf, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	highest = get_highest(array, size);
	for (signf = 1; highest / signf > 0; signf *= 10)
	{
		radix_counting_sort(array, size, signf, buff);
		print_array(array, size);
	}

	free(buff);
}
