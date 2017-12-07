/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** Accept a new client (if there are any)
*/

int						ft_accept_client(t_env *env)
{

	struct sockaddr_in	cliaddr;
	socklen_t			clilen;
	int					connfd;

	/*
	** Check if there are any new client connections
	*/

	if (FD_ISSET(env->listenfd, &env->rset))
	{

		/*
		** Client addr {} len
		*/

		clilen = sizeof(cliaddr);

		/*
		** Accept client, kernel fills cliaddr {}
		*/

		connfd = ft_accept(env->listenfd, (SA *) &cliaddr, &clilen);

		/*
		** Print out new client connected
		*/

		printf("New client connected\n");

		/*
		** Save new client descriptor
		*/

		ft_save_client(env, connfd);

		/*
		** Return TRUE, so caller can check if there are more clients ready
		*/

		return (TRUE);

	}

	return (FALSE);

}