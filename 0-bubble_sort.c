#include "sort.h"

/**
 * swap_int - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sort an array of integers using Bubble sort algorithm.
 * @array: An array of elements to sort.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, n = size;
	int swp;

	if (array == NULL || size < 2)
		return;

	while (1)
	{
		swp = 0;

		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_int(&array[i], &array[i + 1]);
				for (j = 0; j < size - 1; j++)
				{
					printf("%d, ", array[j]);
				}
				printf("%d\n", array[size - 1]);
				swp = 1;
			}
		}

		if (!swp)
		{
			break;
		}

		n--;
	}
}
