/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:11:26 by fbarrier          #+#    #+#             */
/*   Updated: 2022/01/23 22:19:02 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_left(t_program *program, int x, int y)
{
	if (program->tab[y][x - 1] == '1')
		return (0);
	else if (program->tab[y][x - 1] == 'E')
	{
		if (program->collected_nmb >= program->collectible_nmb)
			ft_close_exit (program);
		else
			return (0);
	}
	else if (program->tab[y][x - 1] == 'C')
	{
		program->collected_nmb++;
		ft_replace_left(program, x, y);
	}
	else
		ft_swap (&program->tab[y][x - 1], &program->tab[y][x]);
	mlx_put_image_to_window(program->image.mlx, program->image.win,
		program->image.floor, program->sprite_pos_x, program->sprite_pos_y);
	program->char_pos_x = ft_elt_pos_x(*program, 'P');
	program->char_pos_y = ft_elt_pos_y(*program, 'P');
	program->sprite_pos_x = (program->char_pos_x % program->map_size_x * 64);
	program->sprite_pos_y = (program->char_pos_y % program->map_size_y * 64);
	mlx_put_image_to_window(program->image.mlx, program->image.win,
		program->image.char_left, program->sprite_pos_x, program->sprite_pos_y);
	return (1);
}

int	ft_move_right(t_program *program, int x, int y)
{
	if (program->tab[y][x + 1] == '1')
		return (0);
	else if (program->tab[y][x + 1] == 'E')
	{
		if (program->collected_nmb >= program->collectible_nmb)
			ft_close_exit (program);
		else
			return (0);
	}
	else if (program->tab[y][x + 1] == 'C')
	{
		program->collected_nmb++;
		ft_replace_right(program, x, y);
	}
	else
		ft_swap (&program->tab[y][x + 1], &program->tab[y][x]);
	mlx_put_image_to_window(program->image.mlx, program->image.win,
		program->image.floor, program->sprite_pos_x, program->sprite_pos_y);
	program->char_pos_x = ft_elt_pos_x(*program, 'P');
	program->char_pos_y = ft_elt_pos_y(*program, 'P');
	program->sprite_pos_x = (program->char_pos_x % program->map_size_x * 64);
	program->sprite_pos_y = (program->char_pos_y % program->map_size_y * 64);
	mlx_put_image_to_window(program->image.mlx, program->image.win,
		program->image.char_ri, program->sprite_pos_x, program->sprite_pos_y);
	return (1);
}

int	ft_move_up(t_program *program, int x, int y)
{
	if (program->tab[y - 1][x] == '1')
		return (0);
	else if (program->tab[y - 1][x] == 'E')
	{
		if (program->collected_nmb >= program->collectible_nmb)
			ft_close_exit (program);
		else
			return (0);
	}
	else if (program->tab[y - 1][x] == 'C')
	{
		program->collected_nmb++;
		ft_replace_up(program, x, y);
	}
	else
		ft_swap (&program->tab[y - 1][x], &program->tab[y][x]);
	mlx_put_image_to_window(program->image.mlx, program->image.win,
		program->image.floor, program->sprite_pos_x, program->sprite_pos_y);
	program->char_pos_x = ft_elt_pos_x(*program, 'P');
	program->char_pos_y = ft_elt_pos_y(*program, 'P');
	program->sprite_pos_x = (program->char_pos_x % program->map_size_x * 64);
	program->sprite_pos_y = (program->char_pos_y % program->map_size_y * 64);
	mlx_put_image_to_window(program->image.mlx, program->image.win,
		program->image.char_up, program->sprite_pos_x, program->sprite_pos_y);
	return (1);
}

int	ft_move_down(t_program *program, int x, int y)
{
	if (program->tab[y + 1][x] == '1')
		return (0);
	else if (program->tab[y + 1][x] == 'E')
	{
		if (program->collected_nmb >= program->collectible_nmb)
			ft_close_exit (program);
		else
			return (0);
	}
	else if (program->tab[y + 1][x] == 'C')
	{
		program->collected_nmb++;
		ft_replace_down(program, x, y);
	}
	else
		ft_swap (&program->tab[y + 1][x], &program->tab[y][x]);
	mlx_put_image_to_window(program->image.mlx, program->image.win,
		program->image.floor, program->sprite_pos_x, program->sprite_pos_y);
	program->char_pos_x = ft_elt_pos_x(*program, 'P');
	program->char_pos_y = ft_elt_pos_y(*program, 'P');
	program->sprite_pos_x = (program->char_pos_x % program->map_size_x * 64);
	program->sprite_pos_y = (program->char_pos_y % program->map_size_y * 64);
	mlx_put_image_to_window(program->image.mlx, program->image.win,
		program->image.char_down, program->sprite_pos_x, program->sprite_pos_y);
	return (1);
}

int	ft_key_hook(int keycode, t_program *program)
{
	static int	moves_counter = 0;

	if (keycode == 0 && ft_move_left(program, program->char_pos_x,
			program->char_pos_y) == 1)
		printf("moves: %d\n", ++moves_counter);
	else if (keycode == 2 && ft_move_right(program, program->char_pos_x,
			program->char_pos_y) == 1)
		printf("moves: %d\n", ++moves_counter);
	else if (keycode == 13 && ft_move_up(program, program->char_pos_x,
			program->char_pos_y) == 1)
		printf("moves: %d\n", ++moves_counter);
	else if (keycode == 1 && ft_move_down(program, program->char_pos_x,
			program->char_pos_y) == 1)
		printf("moves: %d\n", ++moves_counter);
	return (0);
}
