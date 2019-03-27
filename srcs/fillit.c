/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 01:41:18 by anjansse          #+#    #+#             */
/*   Updated: 2019/01/13 11:09:21 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		solve(t_tetri **pieces, t_map *map, int i)
{
	int x;
	int y;

	if (pieces[i] == NULL)
		return (1);
	y = 0;
	while (y < map->ymax)
	{
		x = 0;
		while (x < map->xmax)
		{
			if (load_tetris(map, pieces[i], x, y))
			{
				if (solve(pieces, map, i + 1))
					return (1);
				else
					remove_tetris(map, pieces[i], x, y);
			}
			++x;
		}
		++y;
	}
	return (0);
}

char			**fillit(char *tetris, t_array *a)
{
	t_tetri	**pieces;
	t_map	*map;

	pieces = store_all_tetriminos(a);
	map = generate_map(tetris);
	while (!solve(pieces, map, 0))
	{
		map = ft_resize_map(map);
	}
	return (map->array);
}

void			print_solution(char **solution)
{
	int i;

	i = 0;
	while (solution[i] != NULL)
	{
		ft_putstr(solution[i]);
		ft_putchar('\n');
		++i;
	}
}
