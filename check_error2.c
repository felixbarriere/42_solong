/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:15:15 by fbarrier          #+#    #+#             */
/*   Updated: 2022/01/23 21:42:14 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b'
		|| str[i - 3] != '.')
		return (0);
	return (1);
}

void	ft_error(char *str)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	ft_walls_around(char **tab)
{
	int	x;
	int	y;

	x = 1;
	y = -1;
	while (++y < ft_strlen(tab[0]) - 1)
	{
		if (tab[0][y] != '1')
			return (0);
	}
	while (tab[x + 1] != NULL)
	{
		if (tab[x][0] != '1' || tab[x][(ft_strlen(tab[0]) - 1) - 1] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (++y < ft_strlen(tab[0]) - 1)
	{
		if (tab[x][y] != '1')
			return (0);
	}
	return (1);
}
