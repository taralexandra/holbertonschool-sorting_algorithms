#include "sort.h"

/**
  * swap - xchange two iems in an array.
  * @a: ptr to the first item.
  * @b: ptr ptr to the second item.
  */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}


/**
  * partition - using the partition of Lomuto.
  * @array: the array to partition with.
  * @low: the index of start from the partition.
  * @high: the index of end of the partition.
  * @size: size of the array in order to print.
  *
  * Return: the final index of the pivot after partition.
  */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
  * quick_sort_recursive - recursive fonction to sort an array
  * with Quick Sort.
  * @array: the array to partition with.
  * @high: the index of end of the partition.
  * @low: the index of start from the partition.
  * @size: size of the array in order to print.
  */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
  * quick_sort - sort an array of ints by crescent order
  * using the quick sort method.
  * @array: the array to sort.
  * @size: the size of the most famous array.
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	quick_sort_recursive(array, 0, size - 1, size);
}
