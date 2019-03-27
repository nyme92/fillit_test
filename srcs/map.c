/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:59:15 by anjansse          #+#    #+#             */
/*   Updated: 2019/01/13 11:21:56 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char					**generate_fresh_map(int x, int y)
{
	char	**emap;
	int		a;
	int		b;

	a = 0;
	emap = (char **)ft_memalloc(sizeof(char *) * (y + 1));
	while (a < y)
	{
		b = 0;
		emap[a] = (char *)ft_memalloc(sizeof(char) * (x + 1));
		while (b < x)
			emap[a][b++] = '.';
		emap[a][b] = '\0';
		a++;
	}
	return (emap);
}

static int				starting_size(char *str)
{
	int		x;
	int		area;
	int		square;

	x = 0;
	square = 0;
	area = ((ft_strlen(str) / 21 + 1) * 4);
	while ((x++ * square++) < area)
		;
	return (x - 1);
}

t_map					*generate_map(char *str)
{
	t_map	*map;
	int		x;
	int		y;

	map = (t_map *)malloc(sizeof(t_map));
	x = starting_size(str);
	y = x;
	map->array = generate_fresh_map(x, y);
	map->xmax = x;
	map->ymax = y;
	return (map);
}

void					ft_free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->ymax)
	{
		free(map->array[i]);
		++i;
	}
	free(map->array);
	free(map);
}

t_map					*ft_resize_map(t_map *old_map)
{
	int		x;
	int		y;
	t_map	*map;

	x = old_map->xmax + 1;
	y = old_map->ymax + 1;
	ft_free_map(old_map);
	map = (t_map*)malloc(sizeof(t_map));
	map->array = generate_fresh_map(x, y);
	map->xmax = x;
	map->ymax = y;
	return (map);
}
