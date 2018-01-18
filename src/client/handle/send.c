# include <client.h>

/*
** Send msg to server
*/

char		*ft_send_to_server(t_cli **env, char *buf)
{

	char	*resp;

	/*
	** Check that user is corrected to the server
	*/

	if (!(*env)->connected)
		return (ft_resp(C_YEL, "$[client]: you are not connected to the server\n"));

	/*
	** Try to send the msg to the server
	*/

	ft_send_response(buf, (*env)->servfd);

	/*
	** read server response into buff
	*/
	
	if ((resp = ft_wreadline((*env)->servfd)))
		return (resp);

	/*
	** Because the client is blocking, for /msg command
	** (i need another read before returning and awaiting for user input)
	*/

	/*
	** Unable to send response
	*/

	return (ft_resp(C_RED, "$[client]: unable to read from the server\n"));

}
