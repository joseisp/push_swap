/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:56:07 by jinacio-          #+#    #+#             */
/*   Updated: 2022/03/11 12:40:55 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

	performs more one algorithm but with tree numbers.

*/

void	lets_go_rotate_tree(t_stacks *t_stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = t_stack_a->n1;
	middle = t_stack_a->next->n1;
	bottom = t_stack_a->next->next->n1;
	if ((top > bottom) && (top > middle) && (middle > bottom))
	{
		swap(t_stack_a, 1);
		shift_down(t_stack_a, 1);
	}
	else if ((top > bottom) && (top > middle) && (middle < bottom))
		shift_up(t_stack_a, 1);
	else if ((top > middle) && (top < bottom) && (middle < bottom))
		swap(t_stack_a, 1);
	else if ((top < middle) && (top < bottom) && (middle > bottom))
	{
		swap(t_stack_a, 1);
		shift_up(t_stack_a, 1);
	}
	else if ((top < middle) && (top > bottom) && (middle > bottom))
		shift_down(t_stack_a, 1);
	else
		return ;
}
