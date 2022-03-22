/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   push.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jinacio- < jinacio-@student.42sp.org.br	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/02/21 16:24:12 by jinacio-		  #+#	#+#			 */
/*   Updated: 2022/03/04 18:34:13 by jinacio-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

/*

	Subfuction PB and PA. performs the exchange of the top of stack_a with
	stack_b and vice versa.

*/

static void	insert_start(t_stacks **t_stack, int num)
{
	t_stacks	*new;

	new = malloc(sizeof(t_stacks));
	if (new)
	{
		new->n1 = num;
		new->next = *t_stack;
		new->previous = NULL;
		if (*t_stack)
			(*t_stack)->previous = new;
		*t_stack = new;
	}
	else
	{
		write(1, ("Error. Please check the memory.! Code: 934\n"), 33);
		exit (1);
	}
}

void	stack_del(t_stacks **head, t_stacks *del)
{
	if (head == NULL || del == NULL)
		return ;
	if (*head == del)
		*head = del->next;
	if (del->next != NULL)
		del->next->previous = del->previous;
	if (del->previous != NULL)
		del->previous->next = del->next;
	free(del);
	return ;
}

void	push_a(t_stacks **t_stack_a, t_stacks **t_stack_b)
{
	int	number_to_input;

	number_to_input = (*t_stack_b)->n1;
	insert_start(t_stack_a, number_to_input);
	stack_del(t_stack_b, *t_stack_b);
	write(1, "pa\n", 3);
}

void	push_b(t_stacks **t_stack_a, t_stacks **t_stack_b)
{
	int	number_to_input;

	number_to_input = (*t_stack_a)->n1;
	insert_start(t_stack_b, number_to_input);
	stack_del(t_stack_a, *t_stack_a);
	write(1, "pb\n", 3);
}
