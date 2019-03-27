
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashulha <ashulha@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:57:55 by ashulha           #+#    #+#             */
/*   Updated: 2017/03/23 16:11:23 by ashulha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checkcolrow(char **t, int k)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 1;
	y = 1;
	if (t[k] != NULL)
	{
		while (t[k][i + 1] != '\0')
		{
			if (t[k][i++] == '\n' && (x == 5 || t[k][i] == '\0'))
			{
				x = 0;
				y++;
			}
			x++;
		}
		if (y != 4 || x != 5)
			return (0);
		if (ft_checkcolrow(t, k + 1) == 0)
			return (0);
	}
	return (1);
}

int		ft_hash(int *h, int n)
{
	if (!(n == 3))
		return (0);
	if ((h[3] == h[2] + 5 && h[3] == h[1] + 6 && h[3] == h[0] + 7) ||
		(h[3] == h[2] + 5 && h[3] == h[1] + 9 && h[3] == h[0] + 10) ||
		(h[3] == h[2] + 5 && h[3] == h[1] + 6 && h[3] == h[0] + 10) ||
		(h[3] == h[2] + 5 && h[3] == h[1] + 10 && h[3] == h[0] + 11) ||
		(h[3] == h[2] + 5 && h[3] == h[1] + 6 && h[3] == h[0] + 11) ||
		(h[3] == h[2] + 5 && h[3] == h[1] + 10 && h[3] == h[0] + 15) ||
		(h[3] == h[2] + 1 && h[3] == h[1] + 5 && h[3] == h[0] + 10) ||
		(h[3] == h[2] + 1 && h[3] == h[1] + 2 && h[3] == h[0] + 7) ||
		(h[3] == h[2] + 1 && h[3] == h[1] + 2 && h[3] == h[0] + 6) ||
		(h[3] == h[2] + 1 && h[3] == h[1] + 2 && h[3] == h[0] + 5) ||
		(h[3] == h[2] + 1 && h[3] == h[1] + 6 && h[3] == h[0] + 11) ||
		(h[3] == h[2] + 1 && h[3] == h[1] + 4 && h[3] == h[0] + 5) ||
		(h[3] == h[2] + 1 && h[3] == h[1] + 2 && h[3] == h[0] + 3) ||
		(h[3] == h[2] + 1 && h[3] == h[1] + 5 && h[3] == h[0] + 6) ||
		(h[3] == h[2] + 1 && h[3] == h[1] + 6 && h[3] == h[0] + 7) ||
		(h[3] == h[2] + 4 && h[3] == h[1] + 5 && h[3] == h[0] + 6) ||
		(h[3] == h[2] + 4 && h[3] == h[1] + 5 && h[3] == h[0] + 10) ||
		(h[3] == h[2] + 4 && h[3] == h[1] + 5 && h[3] == h[0] + 9) ||
		(h[3] == h[2] + 3 && h[3] == h[1] + 4 && h[3] == h[0] + 5))
		return (1);
	return (0);
}

int		ft_checkhash(char **tetriminos, int k, unsigned int i)
{
	int n;
	int h[4];

	n = -1;
	if (tetriminos[k] != NULL)
	{
		while (tetriminos[k][i])
		{
			if (tetriminos[k][i++] == '#')
			{
				if (n >= 3)
					return (0);
				h[++n] = i;
			}
		}
		if (ft_hash(h, n) == 0)
			return (0);
		if (ft_checkhash(tetriminos, k + 1, 0) == 0)
			return (0);
	}
	return (1);
}

int		ft_validation(char **tetriminos)
{
	if (tetriminos == NULL)
		return (0);
	if (ft_checkcolrow(tetriminos, 0) == 0)
		return (0);
	if (ft_checkhash(tetriminos, 0, 0) == 0)
		return (0);
	return (1);
}
