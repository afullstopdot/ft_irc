/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** write n bytes to a file descriptor
*/

size_t			writen(int fd, const void *vptr, size_t n)
{
	size_t		nleft;
	ssize_t		nwritten;
	const char	*ptr;

	ptr = vptr;
	nleft = n;
	while (nleft > 0)
	{
		if ( (nwritten = write(fd, ptr, nleft)) <= 0) {
			if (nwritten < 0 && errno == EINTR)
				nwritten = 0;		/* and call write() again */
			else
				return (-1);			/* error */
		}

		nleft -= nwritten;
		ptr   += nwritten;
	}
	return (n);
}

/*
** wrapper function
*/

void			ft_writen(int fd, void *ptr, size_t nbytes)
{

	/*
	** write n bytes to a fd, on failure exit
	*/

	if (writen(fd, ptr, nbytes) != nbytes)
		ft_fatal_error("failed to write to file descriptor");

}
