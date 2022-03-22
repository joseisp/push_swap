/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:09:17 by jinacio-          #+#    #+#             */
/*   Updated: 2022/03/11 12:28:59 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	unsigned int	n1;
	struct s_stacks	*next;
	struct s_stacks	*previous;

}t_stacks;

typedef struct s_rotate
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
	int	num;
}t_rotate;

typedef struct s_validate
{
	int	i;
	int	j;
	int	num;

}t_validate;

typedef struct s_putindex
{
	int	i;
	int	j;
	int	countf;
	int	*n1;
	int	*final;

}t_putindex;

//main functions

int		main(int argc, char **argv);
int		start_push(char **argv);
int		send_quick(char **argv, t_stacks *t_stack_a);
void	push_swap(t_stacks **t_stack_a, t_stacks **t_stack_b, int length);
void	lets_go_to_rotate(t_stacks **t_stack_a, t_stacks **t_stack_b,
			int length);
void	lets_go_rotate_tree(t_stacks *t_stack_a);
void	lets_go_rotate_five(t_stacks **t_stack_a, t_stacks **t_stack_b,
			int len);
//subfunctions

void	swap(t_stacks *stacks, int n1);
void	shift_up(t_stacks *stacks, int i);
void	shift_down(t_stacks *stacks, int n1);
void	push_b(t_stacks **t_stack_a, t_stacks **t_stack_b);
void	push_a(t_stacks **t_stack_a, t_stacks **t_stack_b);

//validate

void	check_int(char **argi);
void	check_duplicate(char **argi);
void	exit_check_ocorr(void);
void	check_argc(int n1);
void	check_int_max_n_min(char **argv);
void	verify_order(char **argv);
void	verify_memory(int *verify);

//utils

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *c);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);

// initial sort

void	quicksort(int *array, int length);
void	put_in_stack_a(t_stacks *t_stack_a, int *index, int length);

//other functions

void	stack_del(t_stacks **head, t_stacks *del);
void	clean_all_node(t_stacks *head);
#endif
