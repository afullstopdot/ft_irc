# include <server.h>

/*
** close a file descriptor
*/

void	ft_close(int fd)
{

	/*
	** Attempt to close, on fail dump error msg and exit
	*/

	if (close(fd) == -1)
		ft_fatal_error("failed to close file descriptor");

}