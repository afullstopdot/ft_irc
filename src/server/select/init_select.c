# include <server.h>

/*
** Initialize values for select
*/

void		ft_init_select(t_env **env)
{

	int 	i;

	/*
	** counter
	*/

	i = 0;

	/*
	** maxfd + 1 is the current value of the first argument to select(2)
	*/

	(*env)->maxfd = (*env)->listenfd;

	/*
	** the highest index in the client array that is currently in use
	*/

	(*env)->maxi = -1;

	/*
	** initialize clients --
	*/

	while (i < FD_SETSIZE)
	{

		/*
		** -1 indicates available entry
		*/

		(*env)->client[i] = -1;

		/*
		** increment counter
		*/

		i++;

	}

}