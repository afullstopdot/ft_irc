/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_user.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** create a new user by using client index
*/

void		ft_create_user(t_env *env, int c_index)
{

	t_user	*user;

	/*
	** Allocate memory
	*/

	if ((user = (t_user *)malloc(sizeof(t_user))))
	{

		/*
		** nickname is empty by default
		*/

		ft_memset(user->nick, 0, NICKNAME_MAX);

		/*
		** Set index of user in clients array
		*/

		user->c_index = c_index;

		/*
		** Push to front of list
		*/

		user->next = env->users;

		/*
		** env point to head
		*/

		env->users = user;

	}
	else
		ft_fatal_error("failed to malloc memory");

}