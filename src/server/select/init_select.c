/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** Initialize values for select
*/

void		ft_init_select(t_env *env)
{

	int 	i;

	/*
	** counter
	*/

	i = 0;

	/*
	** maxfd + 1 is the current value of the first argument to select(2)
	*/

	env->maxfd = env->listenfd;

	/*
	** the highest index in the client array that is currently in use
	*/

	env->maxi = -1;

	/*
	** initialize clients --
	*/

	while (i < FD_SETSIZE)
	{

		/*
		** -1 indicates available entry
		*/

		env->client[i] = -1;

		/*
		** increment counter
		*/

		i++;

	}

}