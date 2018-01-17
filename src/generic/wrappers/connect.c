#include <irc.h>

/*
** wrapper for connect
*/

void	ft_connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
	if (connect(fd, sa, salen) < 0)
	{
		ft_fatal_error("unable to connect to server");
	}
}