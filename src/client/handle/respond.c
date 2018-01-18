# include <client.h>

/*
** write to fd
*/

void		ft_send_response(char *buff, int connfd)
{

	/*
	** resp (need to append the eof)
	*/

	char	*resp;

	/*
	** Check for NULL pointers
	*/

	if (!buff)
		ft_fatal_error("unable to write to server");

	/*
	** Append eof
	*/

	if ((resp = ft_strjoin(buff, "\n")))
		ft_writen(connfd, ft_strjoin(resp, "\n"), ft_strlen(resp));

}