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
** read from a file descriptor into a circular buffer
*/

ssize_t			ft_read(int fd, t_cbuf *buf, size_t nbytes)
{

	/*
	** Number of bytes read
	*/

	ssize_t		n;

	/*
	** Counter var
	*/

	int			count;

	/*
	** Buffer for reading
	*/

	char		ptr[MAXLINE];

	/*
	** Initialise coubnt
	*/

	count = 0;

	/*
	** Clear buffer
	*/

	ft_strclr(ptr);

	/*
	** Check that the ring buffer is not a NULL pointer
	*/

	if (!buf)
		ft_fatal_error("NULL pointer, cannot read into circular buffer");

	/*
	** Attempt to read
	*/

	if ((n = read(fd, ptr, nbytes)) == -1)
	{

		/*
		** Failed to read
		*/

		ft_fatal_error("failed to read from file descriptor");
	
	}

	/*
	** Copy everything read into circular buffer (also size MAXLINE)
	*/

	while (ptr[count])
	{

		/*
		** Only add to the queue if there is no space (this circular buffer does not overlap)
		** If there is no more space, exit the loop
		*/

		if (!ft_cbuf_full(buf))
		{

			/*
			** Add character to the queue
			*/

			ft_cbuf_put(buf, ((const unsigned char *) ptr)[count]);

		}
		else
			break ;

		/*
		** Increment pointer
		*/

		count++;

	}

	/*
	** Return nuber of bytes read
	*/

	return (n);

}