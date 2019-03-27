/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadthosetetris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:37:17 by anjansse          #+#    #+#             */
/*   Updated: 2019/01/13 11:20:46 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int			legal_check(t_map *map, t_tetri *t, int x, int y)
{
	if (x + t->x[1] < 0 || y + t->y[1] < 0)
		return (1);
	if (x + t->x[2] < 0 || y + t->y[2] < 0)
		return (1);
	if (x + t->x[3] < 0 || y + t->y[3] < 0)
		return (1);
	if (x + t->x[1] > (map->xmax - 1) || y + t->y[1] > (map->ymax - 1))
		return (1);
	if (x + t->x[2] > (map->xmax - 1) || y + t->y[2] > (map->ymax - 1))
		return (1);
	if (x + t->x[3] > (map->xmax - 1) || y + t->y[3] > (map->ymax - 1))
		return (1);
	return (0);
}

static int			ft_is_empty(t_tetri *t, t_map *map, int x, int y)
{
	if (map->array[y][x] != '.')
		return (1);
	if (map->array[(y + t->y[1])][(x + t->x[1])] != '.')
		return (1);
	if (map->array[(y + t->y[2])][(x + t->x[2])] != '.')
		return (1);
	if (map->array[(y + t->y[3])][(x + t->x[3])] != '.')
		return (1);
	return (0);
}

int					load_tetris(t_map *map, t_tetri *t, int x, int y)
{
	if (legal_check(map, t, x, y) == 1)
		return (0);
	else if (ft_is_empty(t, map, x, y) == 1)
		return (0);
	else
	{
		map->array[y][x] = t->c;
		map->array[y + t->y[1]][x + t->x[1]] = t->c;
		map->array[y + t->y[2]][x + t->x[2]] = t->c;
		map->array[y + t->y[3]][x + t->x[3]] = t->c;
	}
	return (1);
}

void				remove_tetris(t_map *map, t_tetri *t, int x, int y)
{
	map->array[y][x] = '.';
	map->array[y + t->y[1]][x + t->x[1]] = '.';
	map->array[y + t->y[2]][x + t->x[2]] = '.';
	map->array[y + t->y[3]][x + t->x[3]] = '.';
}
