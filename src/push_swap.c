/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:09:03 by jinacio-          #+#    #+#             */
/*   Updated: 2022/03/16 19:14:02 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

	Project start. The program starts in this section. There are functions to
	start the entire program and a function auxiliary.

*/

int	main(int argc, char **argv)
{
	check_int(argv);
	check_duplicate(argv);
	check_argc(argc);
	check_int_max_n_min(argv);
	verify_order(argv);
	if (!argc)
		return (0);
	start_push(argv);
}

int	start_push(char **argv)
{
	t_stacks	*t_stack_a;
	t_stacks	*t_stack_b;
	int			length;

	t_stack_a = malloc(sizeof(t_stacks));
	t_stack_a->previous = NULL;
	t_stack_a->next = NULL;
	if (!(t_stack_a))
	{
		write(1, "Error. Check the allocation of memory. Code: 824", 49);
		exit (1);
	}
	t_stack_b = NULL;
	length = send_quick(argv, t_stack_a);
	push_swap(&t_stack_a, &t_stack_b, length);
	clean_all_node(t_stack_a);
	return (0);
}

void	clean_all_node(t_stacks *head)
{
	t_stacks	*current;
	t_stacks	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free (current);
		current = next;
	}
}
