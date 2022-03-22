/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_anything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:49:39 by jinacio-          #+#    #+#             */
/*   Updated: 2022/03/11 12:36:14 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

	Performs the algorithm radixsort.

*/

void	lets_go_to_rotate(t_stacks **t_stack_a, t_stacks **t_stack_b, int len)
{
	t_rotate	t_var;

	t_var.max_num = len;
	t_var.max_bits = 0;
	t_var.j = 0;
	while ((t_var.max_num >> t_var.max_bits) != 0)
		t_var.max_bits++;
	t_var.i = 0;
	while (t_var.i < t_var.max_bits)
	{
		while (t_var.j < len)
		{
			t_var.num = (*t_stack_a)->n1;
			if (((t_var.num >> t_var.i) & 1) == 1)
				shift_up((*t_stack_a), 1);
			else
				push_b(t_stack_a, t_stack_b);
			t_var.j++;
		}
		t_var.j = 0;
		while ((*t_stack_b))
			push_a(t_stack_a, t_stack_b);
		t_var.i++;
	}
}
