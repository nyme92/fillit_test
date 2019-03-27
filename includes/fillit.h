/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:34:46 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/26 19:44:37 by muelfaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_tetri {
	int				x[4];
	int				y[4];
	char			c;
}					t_tetri;

typedef struct		s_array {
	char			*whole_t;
	char			**each_t;
}					t_array;

typedef struct		s_map {
	char			**array;
	int				xmax;
	int				ymax;
}					t_map;

char				*read_file(int fd,char *str);
int					check_lines(char *str);
int		ft_checkcolrow(char **t, int k);
int		ft_hash(int *h, int n);
int		ft_checkhash(char **tetriminos, int k, unsigned int i);
int		ft_validation(char **tetriminos);
int					check_colrow(char *str);
int					check_char(char *str);
int					check_hash(char *str);
int					check_links(char *str);
int					main_check(char *str);
int					beg_tetrivalue(char *str, int pos);
int					end_tetrivalue(char *str, int pos);
char				**split_tetris(char *str);
t_tetri				*go_next_tetriminos(char **tet, int current_t);
char				**generate_fresh_map(int x, int y);
t_map				*generate_map(char *str);
void				ft_free_map(t_map *map);
t_map				*ft_resize_map(t_map *old_map);
t_tetri				**store_all_tetriminos(t_array *a);
int					load_tetris(t_map *map, t_tetri *t, int x, int y);
void				remove_tetris(t_map *map, t_tetri *t, int x, int y);
char				**fillit(char *tetris, t_array *a);
void				print_solution(char **solution);

#endif
