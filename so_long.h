/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:15:16 by fbarrier          #+#    #+#             */
/*   Updated: 2022/01/23 22:17:02 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

# include "mlx_linux/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line/get_next_line.h"

/* vector with an x and y */
typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

/* all info needed for an image */
typedef struct s_image
{
	void		*mlx;
	void		*win;
	void		*char_left;
	void		*char_ri;
	void		*char_up;
	void		*char_down;
	void		*collectible;
	void		*floor;
	void		*exit;
	void		*wall;
	t_vector	*size;
}	t_image;

/* A pointer to the window and its size */
typedef struct s_window {
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_map {
	void	*floor;
	void	*wall;
}		t_map;

/* all info needed for an image */
typedef struct s_program {
	void		*mlx;
	t_window	win;
	t_image		sprite;
	int			sprite_pos_x;
	int			sprite_pos_y;
	int			map_size_x;
	int			map_size_y;
	int			char_pos_x;
	int			char_pos_y;
	int			collectible_nmb;
	int			collected_nmb;
	int			player_nmb;
	int			exit_nmb;
	t_image		image;
	char		**tab;
	t_map		map;
}				t_program;

/* The 4 values that define a color */
typedef struct s_color {
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

// void		ft_parse_map(t_program program, char **line);
int			ft_check_ber(char *str);
// void		ft_init_map(t_program program);
int			ft_check_error(t_program *program);
int			ft_check_ber(char *str);
void		ft_error(char *str);
int			ft_walls_around(char **tab);
t_program	*ft_fill_info_program(t_program *program);
char		**ft_fill_tab(char *file);
void		*ft_img(void *mlx, char *path);
int			ft_elt_pos_x(t_program program, char c);
int			ft_elt_pos_y(t_program program, char c);
int			ft_size_y(char **tab);
void		ft_swap(char *a, char *b);
void		ft_fill_flo(t_program *program, int x, int y, char **tab);
void		ft_fill_rest(t_program *program, int x, int y, char **tab);
int			ft_key_hook(int keycode, t_program *program);
int			ft_close_exit(t_program *program);
void		ft_replace_right(t_program *program, int x, int y);
void		ft_replace_left(t_program *program, int x, int y);
void		ft_replace_up(t_program *program, int x, int y);
void		ft_replace_down(t_program *program, int x, int y);

#endif
