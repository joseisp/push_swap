/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_four_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:44:38 by jinacio-          #+#    #+#             */
/*   Updated: 2022/03/11 12:40:34 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

	performs another algorithm but with four and five numbers.

*/

void	lets_go_rotate_five(t_stacks **t_stack_a, t_stacks **t_stack_b, int len)
{
	int	i;

	if (len == 4)
		i = (*t_stack_a)->next->next->next->n1;
	if (len == 5)
		i = (*t_stack_a)->next->next->next->next->n1;
	if (i == 0 && len == 5)
		shift_down((*t_stack_a), 1);
	while ((*t_stack_a)->n1 != 0)
		shift_up((*t_stack_a), 1);
	push_b(t_stack_a, t_stack_b);
	if (len == 5)
	{
		while ((*t_stack_a)->n1 != 1)
			shift_up((*t_stack_a), 1);
		push_b(t_stack_a, t_stack_b);
	}
	lets_go_rotate_tree((*t_stack_a));
	if (len == 4)
		push_a(t_stack_a, t_stack_b);
	if (len == 5)
	{
		push_a(t_stack_a, t_stack_b);
		push_a(t_stack_a, t_stack_b);
	}
}
