# include <client.h>

/*
** Main loop for handling clients simulantaneously
*/

void					ft_main_loop(t_cli *env)
{
	int					nready;
	int 				i;
	int					sockfd;

	/*
	** Infinite loop
	*/

	while (42)
	{

		/*
		** Clear sets
		*/

		FD_ZERO(&env->rset);
		FD_ZERO(&env->wset);

		/*
		** Set the fds we want to read/write
		*/

		for (i = 0; i <= env->maxi; i++)
		{
	
			/*
			** Check if a valid fd
			*/
	
			if ((sockfd = env->client[i]) < 0)
				continue ;

			/*
			** Check if we can write to the buffer
			*/

			if (env->nodes[i].wbuf.done)
				FD_SET(sockfd, &env->wset);
			
			/*
			** fd to read from
			*/

			FD_SET(sockfd, &env->rset);
	
		}

		/*
		** read select
		*/

		nready = ft_select(env->maxfd + 1, &env->rset, &env->wset, NULL, NULL);

		/*
		** Check descriptors
		*/

		ft_check_client(&env, &nready);

	}

    return ;
}
