/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:35:55 by fbarrier          #+#    #+#             */
/*   Updated: 2022/01/23 22:17:09 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_program	*ft_fill_info_program(t_program *program)
{	
	program->map_size_x = ft_strlen(program->tab[1]) - 1;
	program->map_size_y = ft_size_y(program->tab);
	program->char_pos_x = ft_elt_pos_x(*program, 'P');
	program->char_pos_y = ft_elt_pos_y(*program, 'P');
	program->sprite_pos_x = (program->char_pos_x % program->map_size_x * 64);
	program->sprite_pos_y = (program->char_pos_y % program->map_size_y * 64);
	program->image.mlx = mlx_init();
	program->image.wall = ft_img(program->image.mlx, "img/wall.xpm");
	program->image.floor = ft_img(program->image.mlx, "img/floor.xpm");
	program->image.char_down = ft_img(program->image.mlx, "img/sacha_down.xpm");
	program->image.char_left = ft_img(program->image.mlx, "img/sacha_left.xpm");
	program->image.char_ri = ft_img(program->image.mlx,
			"img/sacha_right.xpm");
	program->image.char_up = ft_img(program->image.mlx, "img/sacha_up.xpm");
	program->image.collectible = ft_img(program->image.mlx,
			"img/collectible.xpm");
	program->image.exit = ft_img(program->image.mlx, "img/exit.xpm");
	program->image.win = mlx_new_window(program->image.mlx,
			program->map_size_x * 64, program->map_size_y * 64, "so_long");
	program->collected_nmb = 0;
	return (program);
}

void	ft_fill_flo(t_program *program, int x, int y, char **tab)
{
	int	k;
	int	l;

	k = 0;
	while (k < y)
	{
		l = 0;
		while (l < x)
		{
			if (tab[k][l] == '1')
				mlx_put_image_to_window(program->image.mlx, program->image.win,
					program->image.wall, l * 64, k * 64);
			else if (tab[k][l] == 'P' || tab[k][l] == '0' || tab[k][l] == 'C')
				mlx_put_image_to_window(program->image.mlx, program->image.win,
					program->image.floor, l * 64, k * 64);
			l++;
		}
		k++;
	}
}

void	ft_fill_rest(t_program *program, int x, int y, char **tab)
{
	int	k;
	int	l;

	k = -1;
	program->collectible_nmb = 0;
	while (++k < y)
	{
		l = -1;
		while (++l < x)
		{
			if (tab[k][l] == 'P')
				mlx_put_image_to_window(program->image.mlx, program->image.win,
					program->image.char_down, l * 64, k * 64);
			else if (tab[k][l] == 'C')
			{
				program->collectible_nmb++;
				mlx_put_image_to_window(program->image.mlx, program->image.win,
					program->image.collectible, l * 64, k * 64);
			}
			else if (tab[k][l] == 'E')
				mlx_put_image_to_window(program->image.mlx, program->image.win,
					program->image.exit, l * 64, k * 64);
		}
	}
}
