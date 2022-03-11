/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarrier <fbarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:28:42 by fbarrier          #+#    #+#             */
/*   Updated: 2022/01/23 22:08:00 by fbarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strcpy2(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int	ft_count_lines(char *file)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}

char	**ft_fill_tab(char *file)
{
	char	**tab;
	int		i;
	int		size;
	char	*line;
	int		fd;

	i = 0;
	size = ft_count_lines(file);
	tab = malloc((size + 1) * sizeof(char *));
	if (!(tab))
		return (NULL);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != 0)
	{
		tab[i] = line;
		i++;
		line = get_next_line(fd);
	}
	tab[i] = NULL;
	free(line);
	close(fd);
	return (tab);
}
