/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** read from a file descriptor
*/

ssize_t			ft_read(int fd, void *ptr, size_t nbytes)
{

	ssize_t		n;

	/*
	** Attempt to read nbytes, on failure exit
	*/

	if ((n = read(fd, ptr, nbytes)) == -1)
	{
	
		/*
		** dump error and exit
		*/

		ft_fatal_error("failed to read from file descriptor");
	
	}

	return (n);

}