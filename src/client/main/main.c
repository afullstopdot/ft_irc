# include <client.h>

int				main(int argc, char **argv)
{

	/*
	** client environment
	*/

	t_cli		env;

	/*
	** Initialize the client env
	*/

	ft_init_env(&env);

	/*
	** Initialize select info
	*/

	ft_init_select(&env);

	/*
	** Check if the user is trying to connect on client startup
	*/

	if (argc == 3)
		ft_wconnect(&env, argv);

	/*
	** Main loop for handling multiple clients simulaneously
	*/

	ft_main_loop(&env);

	/*
	** End
	*/

    return (EXIT_SUCCESS);
}