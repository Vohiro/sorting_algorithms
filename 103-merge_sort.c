#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t center,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarray - To sort a subarray of integers.
 * @subarr: subarray of an array of integers to sort.
 * @buff: buffer to store the sorted subarray.
 * @front front index of the array.
 * @center: middle index of the array.
 * @back: back index of the array.
 */
void merge_subarray(int *subarr, int *buff, size_t front, size_t center,
		size_t back)
{
	size_t a, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, center - front);

	printf("[right]: ");
	print_array(subarr + center, back - center);

	for (a = front, j = center; a < center && j < back; k++)
		buff[k] = (subarr[a] < subarr[j]) ? subarr[a++] : subarr[j++];
	for (; a < center; a++)
		buff[k++] = subarr[a];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (a = front, k = 0; a < back; a++)
		subarr[a] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - To implement the merge sort algorithm through recursion.
 * @subarr: subarray of an array of integers to sort.
 * @buff: buffer to store the sorted result.
 * @front: front index of the subarray.
 * @back: back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t center;

	if (back - front > 1)
	{
		center = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, center);
		merge_sort_recursive(subarr, buff, center, back);
		merge_subarray(subarr, buff, front, center, back);
	}
}

/**
 * merge_sort - To sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
