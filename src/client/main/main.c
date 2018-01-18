# include <client.h>

int				main(int argc, char **argv)
{

	/*
	** client environment
	*/

	t_cli		env;

	/*
	** User input
	*/

	char		*cmd;

	/*
	** Initialize the client env
	*/

	ft_init_env(&env);

	/*
	** Check if the user is trying to connect on client startup
	*/

	if (argc == 3)
		ft_wconnect(&env, argv);

	/*
	** Read from stdin
	*/

	while ((cmd = ft_wreadline(0)))
	{
		
		/*
		** check that command is not empty
		*/

		if (ft_strlen(cmd))
		{
			
			/*
			** Handle the commands
			*/

			ft_putendl(ft_handle(&env, cmd));
			ft_putstr(C_RST);

		}
		else
			ft_strdel(&cmd);

		/*
		** Display prompt (username)
		*/

		

	}

	/*
	** End
	*/

    return (EXIT_SUCCESS);
}