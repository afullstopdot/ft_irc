/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** create an endpoint for communication
*/

int		ft_socket(int domain, int type, int protocol)
{

	int	fd;

	fd = -1;

	/*
	** Attempt to create a socket
	*/

	if ((fd = socket(domain, type, protocol)) < 0)
	{

		/*
		** Failed to create a socket, dump error and exit
		*/

		ft_fatal_error("failed to create a socket");
	
	}

	return (fd);

}