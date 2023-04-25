#include "sort.h"

/**
 * counting_sort - a function that sorts an array using the counting sort
 * @array: the array to sort
 * @size: the size of the array
 * Return: Void
 */
void counting_sort(int *array, size_t size)
{
	size_t a; 
	int k = array[0];
	int *sorted_array, *counting_sort;

	if (array == NULL || size <= 1)
		return;

	for (a = 1; a < size; a++)
	{
		if (array[a] > k)
			k = array[a];
	}
	counting_sort = (int *)_calloc((k + 1), sizeof(int));
	if (counting_sort == NULL)
		return;
	for (a = 0; a < size; a++)
	{
		counting_sort[array[a]]++;
	}
	for (a = 1; (int)a <= k; a++)
		counting_sort[a] += counting_sort[a - 1];
	print_array(counting_sort, k + 1);

	sorted_array = (int *) malloc(size * sizeof(int));
	if (sorted_array == NULL)
	{
		free(counting_sort);
		return;
	}
	for (a = 0; a < size; a++)
	{
		sorted_array[counting_sort[array[a]] - 1] = array[a];
		counting_sort[array[a]]--;
	}
	for (a = 0; a < size; a++)
	{
		array[a] = sorted_array[a];
	}
	free(counting_sort);
	free(sorted_array);
}
/**
 * _calloc - custom calloc function
 * @k: the number of elements in the array
 * @size: the size of allocate for each element
 * Return: void
 */
void *_calloc(unsigned int k, unsigned int size)
{
	char *a;
	unsigned int  i;

	a = malloc(k * size);
	if (a == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < (k * size))
	{
		a[i] = 0;
		i++;
	}
	return (a);
}
