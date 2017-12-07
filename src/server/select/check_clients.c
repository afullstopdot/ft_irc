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

/*
** Check all clients for data
*/

void		ft_check_client(t_env *env, int *nready)
{

	int		i;
	int		sockfd;
	size_t	n;
	char	buf[MAXLINE];

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
			** clear buff
			*/

			ft_strclr(buf);

			/*
			** Read from client
			*/

			if ((n = ft_read(sockfd, buf, MAXLINE)) == 0)
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



				/*
				** write (done without select)
				*/

				// ft_writen(sockfd, buf, n);
				printf("%s", buf);
			
			}

			if (--(*nready) <= 0)
				break;
		}

	}

}