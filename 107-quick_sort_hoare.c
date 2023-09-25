#include "sort.h"

void swap_elem(int *first, int *second);
int hoare_partitn(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partitn - To order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: array of integers.
 * @size: size of the array.
 * @left: starting index of the subset to order.
 * @right: ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int hoare_partitn(int *array, size_t size, int left, int right)
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
			swap_elem(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - To implement the quicksort algorithm through recursion.
 * @array: array of integers to sort.
 * @size: size of the array.
 * @left: starting index of the array partition to order.
 * @right: ending index of the array partition to order.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = hoare_partitn(array, size, left, right);
		hoare_sort(array, size, left, partition - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - To sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
