/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

int g_count = 0;

/*
** Main loop for handling clients simulantaneously
*/

void					ft_main_loop(t_env *env)
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
			** For writing, only the file descriptors on which one has 
			** something to write are put in the fd_set in writing (not listenfd)
			*/

			if ((sockfd != env->listenfd) && (ft_strlen(env->users[i].wbuf)))
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
		** Check if there are any new client connections
		*/

		if (ft_accept_client(env))
		{

			/*
			** Check if there are no more readable descriptors
			*/

			if (--nready <= 0)
				continue ;

		}

		/*
		** Check all clients for data
		*/

		ft_check_client(env, &nready);

	}

    return ;
}
