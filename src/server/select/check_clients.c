/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_client.c                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

// error update the problem is not with my select, its worth my find_by_key logic

/*
** Check all clients for data
*/

void		ft_check_client(t_env *env, int *nready)
{

	int		i;
	int		sockfd;
	size_t	n;
	char	*resp;
	t_user *user;

	/*
	** counter
	*/

	i = 0;

	/*
	** Check for fd in sets that can be read from
	*/

	for (i = 0; i <= env->maxi; i++)
	{

		/*
		** Check if a valid fd
		*/

		if ((sockfd = env->client[i]) < 0)
			continue ;

		/*
		** Check if the FD is in the set returned by select
		*/

		if (FD_ISSET(sockfd, &env->rset))
		{

			/*
			** Find the user
			*/

			if ((user = ft_find_user_by_key(env, i)))
			{

				/*
				** clear buff
				*/

				ft_strclr(user->rbuf);

				/*
				** Read from client
				*/

				if ((n = ft_read(sockfd, user->rbuf, MAXLINE)) == 0)
				{

					/*
					** remove client
					*/

					ft_remove_client(env, sockfd, i);

				}
				else
				{

					/*
					** Handle command
					*/

						resp = ft_handle_command(env, user->rbuf, i);
						ft_strcpy(user->wbuf, resp);
						ft_strdel(&resp);

				}

			}

			if (--(*nready) <= 0)
				break;
		}

		/*
		** Check if we can write to fd
		*/

		if (FD_ISSET(sockfd, &env->wset))
		{

			// ft_writen(sockfd, "Hello Client\n\0", 13);
			printf("attempting to write to %d\n", sockfd);

			if (--(*nready) <= 0)
				break;
		}

	}

}