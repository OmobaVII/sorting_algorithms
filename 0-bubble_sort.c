#include "sort.h"

/**
 * bubble_sort - a function that iimplements the Bubble sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, b, temp;

	if (array == NULL && size < 2)
	{
		return;
	}
	for (a = 0; a < size - 1; a++)
	{
		for (b = 0; b < size - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				temp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
