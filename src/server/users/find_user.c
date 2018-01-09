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

t_user		*ft_find_user_by_key(t_env **env, int c_index)
{

	t_user	*head;

	/*
	** Check that there are actually users to send this message to
	*/

	if ((head = (*env)->users))
	{

		/*
		** Loop through users
		*/

		while (head)
		{

			/*
			** Check if it is indeed our user
			*/

			if (head->c_index == c_index)
			{

				/*
				** return user
				*/

				return (head);

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

t_user		*ft_find_user_by_name(t_env **env, char *name)
{

	t_user	*head;

	/*
	** List of users
	*/

	if ((head = (*env)->users))
	{

		/*
		** Loop through users
		*/

		while (head)
		{

			/*
			** Find user by name
			*/

			if (ft_strnequ(head->nick, name, ft_strlen(head->nick)))
			{

				/*
				** return user
				*/

				return (head);

			}

			/*
			** increment
			*/

			head = head->next;

		}

	}

	return (NULL);

}