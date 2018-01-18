# include <server.h>

/*
** Find port number and set int env var
*/

void		ft_init_server_port(int argc, char **argv, t_env *env)
{

	int 	port;

	/*
	** Check that a port is passed
	*/

	if (argc != 2)
		ft_dump_usage();

	/*
	** Set port
	*/

	port = ft_atoi(argv[1]);

	/*
	** Valid port #
	*/

	if (port > 0)
	{

		/*
		** set in server env
		*/

		env->port = port;

	}
	else
		ft_dump_usage();

	return ;
}