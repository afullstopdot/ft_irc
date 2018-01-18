# include <client.h>

/*
** Initialize the client env
*/

void			ft_init_env(t_cli *env)
{

	if (env)
	{

		/*
		** By default we are not connected to any server
		*/

		env->connected = FALSE;

		/*
		** Server fd
		*/

		env->servfd = -1;		

	}

}