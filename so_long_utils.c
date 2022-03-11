/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:07:49 by fbarrier          #+#    #+#             */
/*   Updated: 2022/01/23 22:19:42 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_elt_pos_x(t_program program, char c)
{
	int	i;
	int	j;

	i = 0;
	while (program.tab[i])
	{
		j = 0;
		while (program.tab[i][j])
		{
			if (program.tab[i][j] == c)
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_elt_pos_y(t_program program, char c)
{
	int	i;
	int	j;

	i = 0;
	while (program.tab[i])
	{
		j = 0;
		while (program.tab[i][j])
		{
			if (program.tab[i][j] == c)
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_size_y(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	*ft_img(void *mlx, char *path)
{
	int		x;
	int		y;
	void	*test;

	x = 0;
	y = 0;
	test = mlx_xpm_file_to_image(mlx, path, &x, &y);
	return (test);
}

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
