# include <server.h>

int				main(int argc, char **argv)
{

	/*
	** server environment
	*/

	t_env		*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		ft_fatal_error("could not allocate meory for env");

	/*
	** Create a server
	*/

	ft_create_server(argc, argv, &env);

	/*
	** Initialize select info
	*/

	ft_init_select(&env);

	/*
	** Main loop for handling multiple clients simulaneously
	*/

	ft_main_loop(&env);
	
	/*
	** End
	*/

    return (EXIT_SUCCESS);
}
