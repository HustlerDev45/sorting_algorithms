#include "sort.h"

/**
 * swap_int - Swap 2 ints in an array.
 * @a: First int to swap.
 * @b: Second int to swap.
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sort an array of ints using the selection sort algorithm.
 * @array: Array of ints.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t k, l, min;

	for (k = 0; k < size - 1; k++)
	{
		min = k;
		for (l = k + 1; l < size; l++)
		{
			if (array[l] < array[min])
				min = l;
		}

		if (min != k)
		{
			swap_int(array + k, array + min);
			print_array(array, size);
		}
	}
}
