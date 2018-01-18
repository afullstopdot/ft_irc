/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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