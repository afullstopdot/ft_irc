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

/*
** Main loop for handling clients simulantaneously
*/

void					ft_main_loop(t_env *env)
{
	int					nready;

	/*
	** Infinite loop
	*/

	while (42)
	{

		/*
		** structure assignment
		*/

		env->rset = env->allset;

		/*
		** read select
		*/

		nready = ft_select(env->maxfd + 1, &env->rset, NULL, NULL, NULL);

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
