#include "sort.h"

/**
  * bubble_sort - write a func sorts an array of integers in
  * ascending order using the Bubble sort algo.
  * @array: ptr to the array we want to sort.
  * @size: the size of array.
  */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				swapped = 1;

				print_array(array, size);
			}
		}

		if (swapped == 0)
		{
			break;
		}
	}
}
