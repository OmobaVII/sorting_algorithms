#include "sort.h"
/**
 * shell_sort - a function that sorts an array of int in ascending order
 * using shell sort algorithm, via the Knuth sequence
 * @array: the array of int to sort
 * @size: the size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, a, b;
	int tmp;

	if (array == NULL || size <= 1)
	{
		return;
	}
	while (gap < size)
	{
		gap = gap * 3 + 1;
	}
	gap = (gap - 1) / 3;
	while (gap > 0)
	{
		for (a = gap; a < size; a++)
		{
			tmp = array[a];
			for (b = a; b >= gap && array[b - gap] > tmp; b -= gap)
			{
				array[b] = array[b - gap];
			}
			array[b] = tmp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}

}
