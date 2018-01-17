/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** accept a connection on a socket
*/

int			ft_accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{

	int		n;

	/*
	** Attempt to accept a connection, on failure exit program
	*/

	if ((n = accept(fd, sa, salenptr)) < 0)
	{

		/*
		** dump error message
		*/

		ft_fatal_error("failed to accept connection");

	}

	return (n);

}