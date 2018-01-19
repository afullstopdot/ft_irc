# include <client.h>

/*
** Main loop for handling clients simulantaneously
*/

void					ft_main_loop(t_cli *env)
{
	int					nready;
	int 				i;
	int					sockfd;
	struct timeval tmo;

tmo.tv_sec = 5;
    tmo.tv_usec = 0;
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
		** Set listenfd (accept new clients) on readset only
		*/

		FD_SET(env->listenfd, &env->rset);

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

			if (env->nodes[i].rbuf.done)
				FD_SET(sockfd, &env->wset);
			
			/*
			** fd to read from
			*/

			FD_SET(sockfd, &env->rset);
	
		}

		/*
		** read select
		*/

		nready = ft_select(env->maxfd + 1, &env->rset, &env->wset, NULL, &tmo);

		/*
		** Check descriptors
		*/

		ft_check_client(&env, &nready);

	}

    return ;
}
