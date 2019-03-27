/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 22:02:17 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/26 19:38:15 by muelfaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int			wcol(int x)
{
	if (x < 5)
		return (x);
	else if (x >= 5 && x < 10)
		return (x - 5);
	else if (x >= 10 && x < 15)
		return (x - 10);
	else if (x >= 15 && x < 20)
		return (x - 15);
	return (0);
}

static int			wrow(int x)
{
	if (x < 5)
		return (0);
	else if (x >= 5 && x < 10)
		return (1);
	else if (x >= 10 && x < 15)
		return (2);
	else if (x >= 15 && x < 20)
		return (3);
	return (0);
}

t_tetri				*go_next_tetriminos(char **tet, int current_t)
{
	t_tetri		*piece;
	int			j;
	int			i;
	int			xdif;
	int			ydif;

	if (!(piece = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	j = 0;
	i = 0;
	while (i < 4)
	{
		if (tet[current_t][j++] == '#')
		{
		if (i == 0)
		{
				xdif = wcol(j);
				ydif = wrow(j);
			}
			piece->x[i] = (wcol(j) - xdif);
			piece->y[i] = (wrow(j) - ydif);
			i++;
		
		}
	
	}
		//if (tet[current_t][j++] != '#')
		//	i++;
	return (piece);
}

t_tetri				**store_all_tetriminos(t_array *a)
{
	int		j;
	int		n;
	char	c;
	t_tetri	**all_pieces;

	j = 0;
	c = 'A';
	n = ft_strlen(a->whole_t) / 21 + 1;
	all_pieces = (t_tetri **)malloc(sizeof(t_tetri *) * (n + 1));
	while (j < n)
	{
		all_pieces[j] = go_next_tetriminos(a->each_t, j);
		all_pieces[j]->c = c;
		c++;
		j++;
	}
	all_pieces[j] = NULL;
	return (all_pieces);
}
