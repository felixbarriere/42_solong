/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:04:55 by fbarrier          #+#    #+#             */
/*   Updated: 2022/01/23 21:25:52 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lack_letter(t_program *program, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			program->collectible_nmb++;
		else if (str[i] == 'P')
			program->player_nmb++;
		else if (str[i] == 'E')
			program->exit_nmb++;
		i++;
	}
}

static int	ft_wrong_letter(char *str)
{
	int	i;

	i = 0;
	if (str[0] != '1')
		return (0);
	while (str[i + 1])
	{
		if ((str[i] != '1') && str[i] != '0' && str[i] != 'P' && str[i] != 'C'
			&& str[i] != 'E')
			return (0);
		i++;
	}
	if (str[i - 1] != '1')
		return (0);
	return (1);
}

int	ft_check_square(char **tab)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(tab[0]);
	while (tab[i] != NULL)
	{
		if (ft_strlen(tab[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_error2(t_program *program)
{
	if (ft_check_square(program->tab) == 0)
	{
		ft_error("Votre map n'est pas carré!");
		return (0);
	}
	if (ft_walls_around(program->tab) == 0)
	{
		ft_error("Veuillez entourer la map de murs!");
		return (0);
	}
	return (1);
}

int	ft_check_error(t_program *program)
{
	int	x;

	x = 0;
	while (program->tab[x])
	{
		if (ft_wrong_letter(program->tab[x]) == 0)
		{
			ft_error("Lettre interdite!");
			return (0);
		}
		ft_lack_letter(program, program->tab[x]);
		x++;
	}
	if (program->exit_nmb == 0 || program->collectible_nmb == 0
		|| program->player_nmb == 0)
	{
		ft_error("Il vous manque un P, C ou E!");
		return (0);
	}
	if (ft_check_error2(program) == 0)
		return (0);
	return (1);
}
