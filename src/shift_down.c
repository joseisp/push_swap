/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:34:38 by jinacio-          #+#    #+#             */
/*   Updated: 2022/03/11 12:51:52 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

	Subfuction rra and rrb. Shift down all elements of stack a by 1.

*/

void	print(int i)
{
	if (i == 1)
		write(1, "rra\n", 4);
	if (i == 2)
		write(1, "rrb\n", 4);
}

static int	pickup_last(t_stacks *stacks)
{
	t_stacks	*list_num;

	list_num = stacks;
	while (list_num->next != NULL)
	{
		list_num = list_num->next;
	}
	return (list_num->n1);
}

void	shift_down(t_stacks *stacks, int n1)
{
	t_stacks	*single;
	int			aux_last;
	int			aux_middle;
	int			i;
	int			j;

	single = stacks;
	i = pickup_last(stacks);
	j = 0;
	while (stacks->next != NULL)
	{
		aux_last = stacks->n1;
		if (j == 0)
		{
			stacks->n1 = i;
			j++;
		}
		else
			stacks->n1 = aux_middle;
		stacks = stacks->next;
		aux_middle = aux_last;
	}
	stacks->n1 = aux_middle;
	stacks = single;
	print(n1);
}
