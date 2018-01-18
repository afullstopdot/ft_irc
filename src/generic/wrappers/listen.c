# include <server.h>

/*
** listen for connections on a socket
*/

void		ft_listen(int fd, int backlog)
{

	char	*ptr;

	/*
	** Can override 2nd argument with an environment variable
	*/

	if ((ptr = getenv("LISTENQ")) != NULL)
	{

		/*
		** How many clients can the server backlog
		*/

		backlog = ft_atoi(ptr);
	
	}

	/*
	** List for connections on a socket
	*/

	if (listen(fd, backlog) < 0)
	{

		/*
		** Failed to listen on the socket
		** Dump error and exit
		*/

		ft_fatal_error("failed to listen on socket");

	}

}