#include "sort.h"
/**
 * selection_sort - function that sort an array of integers in ascending order
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t a, b, idx, tmp;

	if (array == NULL && size <= 1)
	{
		return;
	}
	for (a = 0; a < size; a++)
	{
		idx = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[idx])
				idx = b;
		}
		if (idx != a)
		{
			tmp = array[idx];
			array[idx] = array[a];
			array[a] = tmp;
			print_array(array, size);
		}
	}
}
