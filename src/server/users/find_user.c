/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_user.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** Find a user by key
*/

t_user		*ft_find_user_by_key(t_env *env, int c_index)
{

	t_user	*head;
	int		index;

	/*
	** index of our user (if we find him)
	*/

	index = -1;
	/*
	** Check that there are actually users to send this message to
	*/

	if ((head = env->users))
	{

		/*
		** Loop through users
		*/

		while (head)
		{

			/*
			** update index
			*/

			index++;

			/*
			** Check if it is indeed our user
			*/

			if (head->c_index == c_index)
			{

				/*
				** return user
				*/

				return (env->users + (sizeof(t_user) * index));

			}

			/*
			** increment
			*/

			head = head->next;

		}

	}

	/*
	** Failed to find client
	*/

	return (NULL);

}

/*
** Find a user key by name from a channel
*/

int 		ft_find_user_by_name(t_user *users, char *name)
{

	t_user	*head;
	int 	index;

	/*
	** Index of our user
	*/

	index = -1;

	/*
	** List of users
	*/

	if ((head = users))
	{

		/*
		** Loop through users
		*/

		while (head)
		{

			/*
			** increment if we didnt find our user
			*/

			index++;

			/*
			** Find user by name
			*/

			if (ft_strequ(head->nick, name))
			{

				/*
				** return user
				*/

				return (head->c_index);

			}

			/*
			** increment
			*/

			head = head->next;

		}

	}

	return (-1);

}