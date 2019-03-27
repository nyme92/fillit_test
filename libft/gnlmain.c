#include "libft.h"

int		main(int c, char **v)
{
	int		fd;
	char	**buf;
	int		r;

	if (c == 2)
	{
		buf = (char**)ft_memalloc(sizeof(char*) * 1);
		fd = open(v[1], O_RDONLY);
		while (0 < (r = get_next_line(fd, buf)))
			ft_putendl(buf[0]);
		ft_strdel(buf);
		free(buf);
	}
	else
		ft_putstr("usage: get_next_line file\n");
	return (0);
}
