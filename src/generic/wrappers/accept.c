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