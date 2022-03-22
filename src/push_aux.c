/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:29:21 by jinacio-          #+#    #+#             */
/*   Updated: 2022/03/11 12:52:32 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	In this section, there are a many functions about organization, for exemple:
	put_in_array,
	put_in_stack_a,
	put_index,
	push_swap,
	send_quick.
*/

void	put_in_array(char **argv, int *n1)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		n1[j] = ft_atoi(argv[i]);
		j++;
		i++;
	}
}

void	put_in_stack_a(t_stacks *t_stack_a, int *index, int length)
{
	int			i;
	t_stacks	*head;
	t_stacks	*newelement;

	head = t_stack_a;
	i = 0;
	t_stack_a->n1 = index[i];
	i++;
	while (i != length)
	{
		newelement = malloc(sizeof(t_stacks));
		if (!(newelement))
		{
			write(1, "Error. Check the allocation of memory. Code: 830", 49);
			exit (1);
		}
		newelement->previous = t_stack_a;
		newelement->n1 = index[i];
		newelement->next = NULL;
		t_stack_a->next = newelement;
		t_stack_a = t_stack_a->next;
		i++;
	}
	t_stack_a = head;
	free(index);
}

void	put_index(int *c, int length, char **argv, t_stacks *t_stack_a)
{
	t_putindex	t_putindex;

	t_putindex.i = 0;
	t_putindex.countf = 0;
	t_putindex.n1 = malloc(sizeof(int) * length);
	t_putindex.final = malloc(sizeof(int) * length);
	verify_memory(t_putindex.n1);
	verify_memory(t_putindex.final);
	put_in_array(argv, t_putindex.n1);
	while (t_putindex.i != length)
	{
		t_putindex.j = 0;
		while (t_putindex.j != length)
		{
			if (t_putindex.n1[t_putindex.i] == c[t_putindex.j])
			{
				t_putindex.final[t_putindex.countf] = t_putindex.j;
				t_putindex.countf++;
			}
			t_putindex.j++;
		}
		t_putindex.i++;
	}
	free(t_putindex.n1);
	put_in_stack_a(t_stack_a, t_putindex.final, length);
}

void	push_swap(t_stacks **t_stack_a, t_stacks **t_stack_b, int length)
{
	if (length == 2)
		swap((*t_stack_a), 1);
	else if (length == 3)
		lets_go_rotate_tree((*t_stack_a));
	else if ((length == 5) || (length == 4))
		lets_go_rotate_five(t_stack_a, t_stack_b, length);
	else
		lets_go_to_rotate(t_stack_a, t_stack_b, length);
}

int	send_quick(char **argv, t_stacks *t_stack_a)
{
	int	length;
	int	i;
	int	j;
	int	*c;

	i = 1;
	j = 0;
	length = 0;
	while (argv[length])
		length++;
	c = malloc(sizeof(int) * length);
	verify_memory(c);
	while (argv[i])
	{
		c[j] = ft_atoi(argv[i]);
		j++;
		i++;
	}
	quicksort(c, length - 1);
	put_index(c, length - 1, argv, t_stack_a);
	free(c);
	return (length - 1);
}
