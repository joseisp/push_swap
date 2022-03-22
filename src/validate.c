/* ************************************************************************** */
/*																		    */
/*												        :::      ::::::::   */
/*   validate.c									     :+:      :+:    :+:   */
/*												    +:+ +:+         +:+     */
/*   By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:56:13 by jinacio-          #+#    #+#			 */
/*   Updated: 2022/02/03 23:49:33 by jinacio-         ###   ########.fr       */
/*																		    */
/* ************************************************************************** */

#include "push_swap.h"

/*
	In this seccion there are a many functions to validate the program.
	for exemple:
	check_int,
	check_duplicate,
	check_argc,
	check_int_max_n_min.
*/

void	check_int(char **argi)
{
	int	i;
	int	j;

	j = 1;
	while (argi[j])
	{
		i = 0;
		while (argi[j][i])
		{
			if ((argi[j][i] < 48) || (argi[j][i] > 57))
			{
				if (argi[j][i] == 45)
				{
					i++;
					continue ;
				}
				write(1, "Error\n", 6);
				exit (1);
			}
			i++;
		}
		j++;
	}
}

void	check_duplicate(char **argi)
{
	int	j;
	int	n1;
	int	compare;

	j = 1;
	while (argi[j])
	{
		n1 = 1;
		while (argi[n1])
		{
			compare = ft_strncmp(argi[j], argi[n1], (ft_strlen(argi[j]) + 1));
			if ((!compare) && (j != n1))
			{
				write(1, "Error\n", 6);
				exit (1);
			}
			n1++;
		}
		j++;
	}
}

void	check_argc(int n1)
{
	if (n1 <= 1)
		exit (1);
}

void	check_int_max_n_min(char **argv)
{
	int		i;
	int		j;
	int		aux;
	char	*aux1;
	int		compare;

	i = 0;
	j = 1;
	while (argv[i])
		i++;
	while (j < i)
	{
		aux = ft_atoi(argv[j]);
		aux1 = ft_itoa(aux);
		compare = ft_strncmp(aux1, argv[j], ft_strlen(argv[j]));
		if (compare != 0)
		{
			write (1, "Error\n", 6);
			exit (1);
		}
		j++;
		free(aux1);
	}
}
