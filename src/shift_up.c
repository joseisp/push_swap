/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:22:52 by jinacio-          #+#    #+#             */
/*   Updated: 2022/03/11 12:44:28 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

	Subfuction PB and PA. Shift up all elements of stack a by 1.

*/

void	shift_up(t_stacks *stacks, int i)
{
	int	aux_first;
	int	aux_last;
	int	aux_middle;

	aux_first = stacks->n1;
	while (stacks->next != NULL)
	{
		stacks = stacks->next;
		if (stacks->next == NULL)
		{
			aux_last = stacks->n1;
			stacks->n1 = aux_first;
			while (stacks->previous != NULL)
			{
				aux_middle = stacks->previous->n1;
				stacks->previous->n1 = aux_last;
				aux_last = aux_middle;
				stacks = stacks->previous;
			}
			break ;
		}
	}
	if (i == 1)
		write(1, "ra\n", 3);
}
