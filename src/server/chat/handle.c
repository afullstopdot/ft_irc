# include <server.h>

/*
** Handle commands
*/

char		*ft_handle_command(t_env **env, const char *buf, const int c_index)
{

	char	**argv;

	/*
	** break recieved buffer to check if valid command > execute
	*/

	if ((argv = ft_strsplit(buf, ' ')) && ft_dstrlen(argv) > 0)
	{

		/*
		** Set username
		*/

		if (ft_strequ(ft_strtrim(argv[0]), "/nick") && argv[1])
			return (ft_set_username(env, argv, c_index));
		
		/*
		** Get username
		*/

		else if (ft_strequ(ft_strtrim(argv[0]), "/whoami"))
			return (ft_get_username(env, c_index));

		/*
		** Join a channel
		*/

		else if (ft_strequ(ft_strtrim(argv[0]), "/join") && argv[1])
			return (ft_channel_join(env, argv, c_index));

		/*
		** Leave a channel
		*/

		else if (ft_strequ(ft_strtrim(argv[0]), "/leave") && argv[1]) {
			return (ft_channel_leave(env, argv, c_index));
		}

		/*
		** Send a message
		*/

		else if (ft_strequ(ft_strtrim(argv[0]), "/msg") && argv[1] && argv[2])
			return (ft_send_message(env, argv, c_index));

		/*
		** List all users on channel
		*/

		else if (ft_strequ(ft_strtrim(argv[0]), "/who"))
			return (ft_channel_list(env, c_index));

		/*
		** Invalid command
		*/

		else
			return (ft_invalid_command());

	}

	return (ft_invalid_command());

}