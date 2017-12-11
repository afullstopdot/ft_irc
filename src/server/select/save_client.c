/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** Save new client
*/

void	ft_save_client(t_env *env, int connfd)
{

	int	i;

	/*
	** counter variable
	*/

	i = 0;

	/*
	** Save new client descriptor
	*/

	while (i < FD_SETSIZE)
	{

		/*
		** If position is available (will have a value of -1 if available)
		*/

		if (env->client[i] < 0)
		{

			/*
			** Save file descriptor on first available position
			*/

			env->client[i] = connfd;

			/*
			** Done saving, break
			*/

			break ;

		}
		i++;

	}

	/*
	** Create user and add to list
	*/

	ft_create_user(env, i);

	/*
	** Check that we still have space for new clients after trying to save new client
	*/

	if (i == FD_SETSIZE)
		ft_fatal_error("server cannot handle any more clients");

	/*
	** Assign for select
	*/

	if (connfd > env->maxfd)
		env->maxfd = connfd;

	/*
	** Max index in client aaray
	*/

	if (i > env->maxi)
		env->maxi = i;

}
