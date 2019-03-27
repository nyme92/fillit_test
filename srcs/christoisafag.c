/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:51:49 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/25 00:34:49 by muelfaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"


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

	a->each_t = split_tetris(a->whole_t);
	solution = fillit(a->whole_t, a);
	print_solution(solution);
	return (0);
}
