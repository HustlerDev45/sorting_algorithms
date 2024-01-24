#include "sort.h"

/**
 * swap_int - Swap 2 integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of ints according to
 * the lomuto partition scheme.
 * @array: Array of ints.
 * @size: Size of the array.
 * @low: The lower bound of the subset to order.
 * @high: the higher bound of the subset to order.
 *
 * Return: Final partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot, above, below;

	pivot = array[high];
	for (above = below = low; below < high; below++)
	{
		if (array[below] < pivot)
		{
			if (above < below)
			{
				swap_int(array + above, array + below);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > pivot)
	{
		swap_int(array + above, array + high);
		print_array(array, size);
	}

	return (above);
}

/**
 * quick_sort_recursion - Implement the quicksort algo through recursion.
 * @array: Array of ints to sort.
 * @size: Size of the array.
 * @low: The lower bound of the array partition to order.
 * @high: The higher bound of the array partition to order.
 */
void quick_sort_recursion(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, size, low, high);
		quick_sort_recursion(array, size, low, pivot - 1);
		quick_sort_recursion(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort - Sort an array of ints using the quicksort algorithm.
 * @array: Array of ints.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursion(array, size, 0, size - 1);
}
