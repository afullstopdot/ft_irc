/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** synchronous I/O multiplexing
*/

int			ft_select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout)
{
	int		n;

	/*
	** block with select, if failure. exit with dump
	*/

	if ((n = select(nfds, readfds, writefds, exceptfds, timeout)) < 0)
	{

		/*
		** dump error message
		*/

		ft_fatal_error("failed to select");

	}

	/*
	** could possibly return 0 on timeout
	*/

	return (n);

}