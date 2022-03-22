/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:23:47 by jinacio-          #+#    #+#             */
/*   Updated: 2022/03/11 12:52:08 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	In this seccion there is a function to auxiliary the whole program.
	for exemple:
	ft_strlen,
	ft_strncmp,
	ft_itoa,
*/

//--------------- STRLEN ---------------

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

//--------------- STRNCMP ---------------

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 1;
	if (n == 0)
		return (0);
	while (c < n && *s1 && *s2)
	{
		if (*(unsigned char *)s1 == *(unsigned char *)s2)
		{
			s1++;
			s2++;
			c++;
		}
		else
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

//--------------- ITOA ---------------

static void	convert(int c, char *str, long int i)
{
	unsigned int	nbr;

	nbr = c;
	if (c < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr >= 10)
		convert((nbr / 10), str, (i - 1));
	str[i] = (nbr % 10) + '0';
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	j;
	long int	count;

	j = n;
	count = 0;
	if (j <= 0)
		count++;
	while (j)
	{
		j = (j / 10);
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = 0;
	convert (n, str, (count - 1));
	return (str);
}
