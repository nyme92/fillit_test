/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 22:20:17 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/25 15:27:59 by muelfaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		beg_tetrivalue(char *str, int pos)
{
	if (pos <= 21)
	{
		pos = 0;
		return (pos);
	}
	while (str[pos] != '\n' || str[pos - 1] != '\n')
	{
		pos--;
	}
	return (pos);
}

int		end_tetrivalue(char *str, int pos)
{
	int verif;
	int verif2;

	verif = ft_strlen(str);
	verif2 = verif - 21;
	if (pos >= verif2 && pos < verif)
		return (verif);
	while (pos < verif2 && (str[pos] != '\n' || str[pos + 1] != '\n'))
		pos++;
	return (pos);
}

int		check_links(char *str)
{
	int x;
	int count;
	int verif;

	x = 0;
	count = 0;
	verif = ((ft_strlen(str) / 21) + 1) * 6;
	while (str[x])
	{
		if (str[x] == '#')
		{
			if (str[x + 1] == '#')
				count++;
			if (((x - 1) >= 0) && (str[x - 1] == '#'))
				count++;
			if (((x + 5) < end_tetrivalue(str, x)) && (str[x + 5] == '#'))
				count++;
			if (((x - 5) >= beg_tetrivalue(str, x)) && (str[x - 5] == '#'))
				count++;
		}
		x++;
	}
	if (count < verif)
		return (1);
	return (0);
}

int		check_char(char *str)
{
	int		x;
	int		n;

	x = 0;
	while (str[x])
	{
		if (str[x] != '.' && str[x] != '#' && str[x] != '\n')
			printf("fuckYOU");
		x++;
	}
	x = 0;
	while (str[x])
	{
		n = 0;
		while (str[x++] != '\n')
		{
			if (n != 3 && str[x] == '\n')
				return (1);
			n++;
		}
		if (str[x] == '\n' && str[x + 1] == '\n')
			x++;
	}
	return (0);
}

int		check_colrow(char *str)
{
	int		x;
	int		col;
	int		lines;
	int		exeption;

	x = 0;
	lines = 0;
	exeption = 5;
	while (str[x])
	{
		col = 0;
		while (str[x] != '\n')
		{
			if (str[x] == '\n' && col != 3 && lines != exeption)
				return (1);
			x++;
			col++;
		}
		x++;
		lines += 1;
		if (lines == exeption)
			exeption += 5;
	}
	return (0);
}
