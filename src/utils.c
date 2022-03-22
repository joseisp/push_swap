/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:36:22 by jinacio-          #+#    #+#             */
/*   Updated: 2022/03/11 12:48:09 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

	In this seccion there is a function to auxiliary the whole program.

*/

// --------------- ATOI ---------------

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_check_overflow(int num, int c_minus)
{
	unsigned int	nb;

	nb = num;
	if (nb > 2147483648 && c_minus)
		return (0);
	if (nb > 2147483647 && !c_minus)
		return (-1);
	return (1);
}

size_t	ft_skip_space(const char *nptr)
{
	size_t	i;

	i = 0;
	while (nptr[i] == '\n' || nptr[i] == '\f' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	return (i);
}

int	ft_isnegative(const char *nptr, size_t n)
{
	if (!ft_isdigit(nptr[n + 1]))
		return (-1);
	if (nptr[n] == '-')
		return (1);
	else if (nptr[n] == '+')
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *nptr)
{
	size_t	skip_space;
	int		negative;
	int		total;
	int		ret;

	negative = 0;
	total = 0;
	skip_space = ft_skip_space(nptr);
	if (ft_strlen(nptr) == 0)
		return (0);
	if (! ft_isdigit(nptr[skip_space]))
		negative = ft_isnegative(nptr, skip_space++);
	if (negative == -1)
		return (0);
	while (nptr[skip_space] && ft_isdigit(nptr[skip_space]))
		total = (total * 10) + (nptr[skip_space++] - 48);
	ret = ft_check_overflow(total, negative);
	if (ret != 1)
		return (ret);
	if (negative == 1)
		total *= -1;
	return (total);
}
