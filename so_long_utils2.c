/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:56:20 by fbarrier          #+#    #+#             */
/*   Updated: 2022/02/01 16:18:52 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_replace_left(t_program *program, int x, int y)
{
	program->tab[y][x - 1] = 'P';
	program->tab[y][x] = '0';
}

void	ft_replace_right(t_program *program, int x, int y)
{
	program->tab[y][x + 1] = 'P';
	program->tab[y][x] = '0';
}

void	ft_replace_up(t_program *program, int x, int y)
{
	program->tab[y - 1][x] = 'P';
	program->tab[y][x] = '0';
}

void	ft_replace_down(t_program *program, int x, int y)
{
	program->tab[y + 1][x] = 'P';
	program->tab[y][x] = '0';
}
