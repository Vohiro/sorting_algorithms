#include "sort.h"

void swap_elem(int *first, int *second);
void binary_heap(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * binary_heap - Turn a binary tree into a complete binary heap.
 * @array: array of integers representing a binary tree.
 * @size: size of the binary tree.
 * @base: index of the base row of the tree.
 * @root: root node of the binary tree.
 */
void binary_heap(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, biggest;

	left = 2 * root + 1;
	right = 2 * root + 2;
	biggest = root;

	if (left < base && array[left] > array[biggest])
		biggest = left;
	if (right < base && array[right] > array[biggest])
		biggest = right;

	if (biggest != root)
	{
		swap_elem(array + root, array + biggest);
		print_array(array, size);
		binary_heap(array, size, base, biggest);
	}
}

/**
 * heap_sort - To sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int a;

	if (array == NULL || size < 2)
		return;

	for (a = (size / 2) - 1; a >= 0; a--)
		binary_heap(array, size, size, a);

	for (a = size - 1; a > 0; a--)
	{
		swap_elem(array, array + a);
		print_array(array, size);
		binary_heap(array, size, a, 0);
	}
}
