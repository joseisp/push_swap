/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:11:52 by jinacio-          #+#    #+#             */
/*   Updated: 2022/03/11 12:50:41 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	In this seccion there are a many functions to auxiliary the whole program.
	for exemple:
	verify_memory,
	verify_order_aux,
	verify_order,
*/

void	verify_memory(int *verify)
{
	if (!(verify))
	{
		write(1, "Error. Check the allocation of memory. Code: 1020", 49);
		exit (1);
	}
}

void	verify_order_aux(char **argv, int n1, int *compares,
			int *compare_sorted)
{
	t_validate	t_validate;

	t_validate.i = 1;
	t_validate.j = 0;
	while (argv[t_validate.i])
	{
		compare_sorted[t_validate.j] = ft_atoi(argv[t_validate.i]);
		t_validate.j++;
		t_validate.i++;
	}
	quicksort(compare_sorted, n1 - 1);
	t_validate.i = 0;
	while (t_validate.i < n1 - 1)
	{
		if (compares[t_validate.i] != compare_sorted[t_validate.i])
		{
			free(compares);
			free(compare_sorted);
			return ;
		}
		t_validate.i++;
	}
	free(compares);
	free(compare_sorted);
	exit(1);
}

void	verify_order(char **argv)
{
	int	*compares;
	int	i;
	int	j;
	int	n1;
	int	*compare_sorted;

	i = 1;
	j = 0;
	n1 = 0;
	while (argv[n1])
		n1++;
	compares = malloc(sizeof(int) * n1);
	compare_sorted = malloc(sizeof(int *) * n1);
	verify_memory(compares);
	verify_memory(compare_sorted);
	while (argv[i])
	{
		compares[j] = ft_atoi(argv[i]);
		j++;
		i++;
	}
	i = 1;
	j = 0;
	verify_order_aux(argv, n1, compares, compare_sorted);
}
