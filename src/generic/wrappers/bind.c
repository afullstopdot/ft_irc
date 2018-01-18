# include <server.h>

/*
** bind a name to a socket
*/

void	ft_bind(int fd, const struct sockaddr *sa, socklen_t salen)
{

	/*
	** Attempt to bind a socket to a addr
	** If this fails, exit the program
	*/

	if (bind(fd, sa, salen) < 0)
	{

		/*
		** fatal error - exit after dumping error
		*/

		ft_fatal_error("failed to bind name to a socket");

	}

}