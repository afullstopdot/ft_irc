# include <client.h>

/*
** Wrapper for ft_connect_to_server
*/

char	*ft_wconnect_to_client(t_cli **env, char **argv)
{

	/*
	** check that we are using valid arguments
	*/

	if ((*env) && argv)
	{

		/*
		** return if we are connected already
		*/

		if ((*env)->connected)
			return (ft_resp(C_YEL, "$[client]: you are already connected to the server\n"));

		/*
		** Attempt to connect to the server
		*/

		ft_connect_to_server(env, argv);

		/*
		** If we get this far we connected
		*/

		return (ft_resp(C_GRN, "$[client]: connected to server successfully\n"));

	}

	return (ft_resp(C_GRN, "$[client]: unable to connect to server\n"));

}