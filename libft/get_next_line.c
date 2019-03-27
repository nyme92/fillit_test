/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muelfaha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:10:48 by muelfaha          #+#    #+#             */
/*   Updated: 2019/03/25 14:44:41 by muelfaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		tobuff(int fd, char **wholebuff, char **eachline)
{
	char	*str;
	char	*tobecp;

	if ((str = ft_strchr(wholebuff[fd], '\n')))
	{
		tobecp = wholebuff[fd];
		*str = '\0';
		*eachline = ft_strdup(wholebuff[fd]);
		wholebuff[fd] = ft_strdup(str + 1);
		free(tobecp);
		return (1);
	}
	if (*wholebuff[fd])
	{
		*eachline = ft_strdup(wholebuff[fd]);
		wholebuff[fd] = ft_strnew(BUFF_SIZE + 1);
		return (1);
	}
	return (0);
}

int		readline(int fd, char **buffer)
{
	char	*newstr;
	char	*temp;
	int		readbuffer;

	newstr = ft_strnew(BUFF_SIZE + 1);
	while ((readbuffer = read(fd, newstr, BUFF_SIZE)) > 0)
	{
		temp = buffer[fd];
		buffer[fd] = ft_strjoin(buffer[fd], newstr);
		free(temp);
		if (!buffer[fd])
		{
			buffer[fd] = ft_strdup(newstr);
		}
		
		ft_memset(newstr, 0, BUFF_SIZE);
	}
	free(newstr);
	return (readbuffer);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buff[4860];

	if (!line)
		return (-1);
	if (0 > fd)
		return (-1);
	if (0 > BUFF_SIZE)
		return (-1);
	if (readline(fd, &buff[fd]))
		return (-1);
	if (tobuff(fd, &buff[fd], line))
		return (1);
	return (0);
}
