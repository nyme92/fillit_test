/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:51:49 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/24 22:11:44 by muelfaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static char			*append(char *tetris, size_t size)
{
	char	*new_tetris;
	size_t	old_size;

	new_tetris = (char *)malloc(sizeof(char) * size);
	ft_memset(new_tetris, 0, size);
	old_size = ft_strlen(tetris);
	ft_memcpy(new_tetris, tetris, old_size);
	free(tetris);
	return (new_tetris);
}

char				*read_file(int fd)
{
	char *tetris;
	char		*tmp;
	int			count_tet;
	int			next;

	next = 22;
	tetris = ft_strnew(21);
	tmp = ft_strnew(21);
	while ((count_tet = read(fd, tmp, 21)))
	{
		ft_strcat(tetris, tmp);
		next += 21;
		tetris = append(tetris, next);
		ft_memset(tmp, 0, 21);
	}
	if (main_check(tetris) ||
			(ft_strlen(tetris) < 20 || ft_strlen(tetris) > 547))
	{
		ft_putstr("error\n");
		exit(1);
	}
	return (tetris);
}

int		main(int argc, char **argv)
{
	t_array		*a;
	int x;
	int fd;
	char *string;
	char **solution;
	a = (t_array *)malloc(sizeof(t_array));
	a->whole_t = "";
	if (argc != 2)
	{
		ft_putstr("usage : ./fillit [FILE] program <filename>\n");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	while ((x = get_next_line(fd,&string) > 0))
	{		a->whole_t = ft_strjoin(a->whole_t, ft_strjoin(string, "\n"));
	}
	if (fd == -1)
		ft_putstr("error");
	if (fd == 0)
		ft_putstr ("error");
	if (!main_check(string))
		ft_putstr("error");
	a->each_t = split_tetris(a->whole_t);
	solution = fillit(a->whole_t, a);
	print_solution(solution);
	return (0);
}
