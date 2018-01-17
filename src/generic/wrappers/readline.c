/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 14:48:03 by amarquez          #+#    #+#             */
/*   Updated: 2017/06/21 14:48:04 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

char			get_char(int fd)
{
	char		c;

	read(fd, &c, 1);
	return (c);
}

void			resize_str(char **str, size_t new_size)
{
	char		*tmp;

	tmp = str[0];
	str[0] = ft_strnew(new_size);
	if (str[0] != NULL)
	{
		ft_strcpy(str[0], tmp);
		ft_strdel(&tmp);
	}
}

static char		*ft_readline(int fd)
{
	char		*line;
	char		c;
	int			loop;
	int			size;

	loop = 0;
	size = 50;
	line = ft_strnew(size);
	if (line == NULL)
		return (NULL);
	while (1)
	{
		c = get_char(fd);
		if (c == '\n' || c == '\0')
		{
			line[loop] = '\0';
			return (line);
		}
		line[loop++] = c;
		if (loop >= size - 1)
		{
			size *= 2;
			resize_str(&line, size);
		}
	}
}

/*
** wrapper for ft_readline
*/

char			*ft_wreadline(int fd)
{
	char		*n;

	if (!(n = ft_readline(fd)))
		ft_fatal_error("unable to read from stdin");
	return (n);
}