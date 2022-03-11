/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:49:46 by fbarrier          #+#    #+#             */
/*   Updated: 2022/02/01 16:04:33 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_exit(t_program *program)
{
	printf ("So long my friend!");
	mlx_destroy_window (program->image.mlx, program->image.win);
	exit (0);
}

int	ft_close_cross(t_program *program)
{
	printf ("Maybe next time!");
	mlx_destroy_window(program->image.mlx, program->image.win);
	exit(0);
}

int	ft_close_esc(int keycode, t_program *program)
{
	if (keycode == 53)
	{
		printf ("Maybe next time!");
		mlx_destroy_window (program->image.mlx, program->image.win);
		exit(0);
	}
	return (0);
}

void	ft_init_map(t_program program)
{
	ft_fill_info_program(&program);
	ft_fill_flo(&program, program.map_size_x, program.map_size_y, program.tab);
	ft_fill_rest(&program, program.map_size_x, program.map_size_y, program.tab);
	mlx_hook(program.image.win, 2, 1L << 0, ft_close_esc, &program);
	mlx_hook(program.image.win, 17, 0L, ft_close_cross, &program);
	mlx_key_hook(program.image.win, ft_key_hook, &program);
	mlx_loop(program.image.mlx);
}

int	main(int ac, char **av)
{
	t_program	program;

	if (ac != 2)
	{
		ft_error("Mauvais nombre d'arguments!");
		return (1);
	}
	if (ft_check_ber(av[1]) == 0)
	{
		ft_error("Mauvaise extention!");
		return (1);
	}
	program.tab = ft_fill_tab(av[1]);
	program.collectible_nmb = 0;
	program.player_nmb = 0;
	program.exit_nmb = 0;
	if (ft_check_error(&program) == 0)
		exit (1);
	ft_init_map(program);
}
