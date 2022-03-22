/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:21:37 by jinacio-          #+#    #+#             */
/*   Updated: 2022/03/11 12:45:05 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

	Subfuction SA and SB. Swap the first 2 elements at the top of stack a.

*/

void	swap(t_stacks *stacks, int n1)
{
	int	i;
	int	aux;

	i = stacks->n1;
	aux = stacks->next->n1;
	stacks->n1 = aux;
	stacks->next->n1 = i;
	if (n1 == 1)
		write(1, "sa\n", 3);
	if (n1 == 2)
		write(1, "sb\n", 3);
}
