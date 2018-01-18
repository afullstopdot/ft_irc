# include <client.h>

/*
** Handle the user input
*/

char		*ft_handle(t_cli *env, char *buf)
{

	char	**argv;

	/*
	** break recieved buffer to check if valid command > execute
	*/

	if ((argv = ft_strsplit(buf, ' ')))
	{

		/*
		** Connect to a server [/connect server port]
		*/

		if (ft_strequ(ft_strtrim(argv[0]), "/connect") && argv[1] && argv[2])
			return (ft_wconnect_to_client(env, argv));
		
		/*
		** Write to server
		*/

		return (ft_invalid_command());

	}

	return (ft_invalid_command());

}