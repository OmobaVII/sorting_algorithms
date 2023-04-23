#include "sort.h"

/**
 * l_partition - a function that implements the lumuto algorithm
 * @array: the array
 * @low: the lowest element
 * @high: the highest element
 * @size: the size of the array
 * Return: the pivot
 */
int l_partition(int *array, int low, int high, size_t size)
{
	int pivot;
	int a, b, tmp, tmp1;

	pivot = array[high];
	b = low;
	for (a = low; a < high; a++)
	{
		if (array[a] < pivot)
		{
			if (b != a)
			{
				tmp = array[b];
				array[b] = array[a];
				array[a] = tmp;
				print_array(array, size);
			}
			b++;
		}
	}
	if (high != b && array[high] != array[b])
	{
		tmp1 = array[high];
		array[high] = array[b];
		array[b] = tmp1;
		print_array(array, size);
	}
	return (b);
}
/**
 * quick_sort_help - a function that helps the quick sort
 * @array: the array
 * @low: the lowest integer
 * @high: the highest
 * @size: the size of the array
 * Return: void
 */
void quick_sort_help(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = l_partition(array, low, high, size);
		quick_sort_help(array, low, p - 1, size);
		quick_sort_help(array, p + 1, high, size);
	}
}
/**
 * quick_sort - a function that performs a quick sort
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
	{
		return;
	}

	quick_sort_help(array, 0, size - 1, size);
}

