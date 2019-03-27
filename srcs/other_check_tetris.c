/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jawatter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:48:00 by jawatter          #+#    #+#             */
/*   Updated: 2019/03/26 19:37:41 by muelfaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			check_hash(char *str)
{
	int hashnum;
	int x;

	x = 0;
	while (str[x])
	{
		hashnum = 0;
		if (str[x] == '\n' && str[x + 1] == '\n')
			x++;
		while ((str[x] != '\n' || str[x + 1] != '\n') && str[x])
		{
			if (str[x] == '#')
				hashnum += 1;
			x++;
		}
		if (hashnum != 4)
			return (1);
	}
	return (0);
}

int			check_lines(char *str)
{
	int x;
	int count;

	x = 0;
	while (str[x])
	{
		count = 0;
		while (str[x + 1] != '\0' && (str[x] != '\n' || str[x + 1] != '\n'))
		{
			x++;
			if (str[x] == '\n' || str[x] == '\0')
				count++;
		}
		if (count != 4)
			return(1);
		x++;
	}
	return (0);
}



char		**split_tetris(char *str)
{
	char	**tetris;
	int		b;
	int		x;
	int		a;

	a = 0;
	x = 0;
	if (!(tetris = (char **)ft_memalloc(sizeof(char *)
					* (ft_strlen(str) / 21 + 1))))
		ft_strdel(tetris);
	while (a != (ft_strlen(str) / 21 + 1))
	{
		b = 0;
		tetris[a] = (char *)ft_memalloc(sizeof(char) * 21);
		while ((str[x] != '\n' || str[x + 1] != '\n') && str[x + 1])
			tetris[a][b++] = str[x++];
		a++;
		if (str[x] == '\0')
			break ;
		x = x + 2;
	}
	return (tetris);
}
