# include <server.h>

/*
** Accept a new client (if there are any)
*/

int						ft_accept_client(t_env **env)
{

	struct sockaddr_in	cliaddr;
	socklen_t			clilen;
	int					connfd;

	/*
	** Check if there are any new client connections
	*/

	if (FD_ISSET((*env)->listenfd, &(*env)->rset))
	{

		/*
		** Client addr {} len
		*/

		clilen = sizeof(cliaddr);

		/*
		** Accept client, kernel fills cliaddr {}
		*/

		connfd = ft_accept((*env)->listenfd, (SA *) &cliaddr, &clilen);

		/*
		** dump connection info
		*/

		printf("new client connected: %s, port %d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

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