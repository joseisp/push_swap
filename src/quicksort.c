/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:22:08 by jinacio-          #+#    #+#             */
/*   Updated: 2022/03/11 12:35:07 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

	Performs the quicksort. The program arranges the numbers in ascending order.

*/

void	swaps(int *first, int *second)
{
	int	aux;

	aux = *first;
	*first = *second;
	*second = aux;
}

int	partition(int *array, int low, int high)
{
	int	pivot_index;
	int	i;
	int	j;

	pivot_index = array[high];
	j = low;
	i = (low - 1);
	while (j < high)
	{
		if (array[j] <= pivot_index)
		{
			i++;
			swaps(&array[i], &array[j]);
		}
		j++;
	}
	swaps(&array[i + 1], &array[high]);
	return (i + 1);
}

void	quicksort_recursion(int *array, int low, int high)
{
	int	pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high);
		quicksort_recursion(array, low, pivot_index - 1);
		quicksort_recursion(array, pivot_index + 1, high);
	}
}

void	quicksort(int *array, int length)
{
	quicksort_recursion(array, 0, length - 1);
}
