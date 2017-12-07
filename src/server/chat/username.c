/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   username.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** set username
*/

char		*ft_set_username(t_env *env, char **argv, int c_index)
{

	t_user	*head;

	/*
	** Assign list
	*/

	if ((head = env->users))
	{

		/*
		** Iterate through list
		*/

		while (head)
		{

			/*
			** Check if correct user
			*/

			if (head->c_index == c_index)
			{

				/*
				** Check if valid username (9 characters max)
				*/

				if (ft_strlen(argv[1]) <= NICKNAME_MAX)
				{

					/*
					** copy into string
					*/

					ft_strcpy(head->nick, ft_strtrim(argv[1]));

					/*
					** Username set
					*/

					return (ft_usuccess("$[server]: username updated, check with /whoami\n"));
				
				}

			}

			/*
			** increment
			*/

			head = head->next;

		}

	}

	/*
	** username not set
	*/

	return (ft_uerror("$[server]: unable to update your username\n"));

}

/*
** get username
*/

char		*ft_get_username(t_env *env, int c_index)
{

	t_user	*head;

	/*
	** Assign list
	*/

	if ((head = env->users))
	{

		/*
		** Iterate through list
		*/

		while (head)
		{

			/*
			** Check if correct user
			*/

			if (head->c_index == c_index)
			{

				/*
				** Check if valid username (9 characters max)
				*/

				if (ft_strlen(head->nick))
				{

					/*
					** get username
					*/

					return (ft_resp(C_CYN, ft_strjoin(head->nick, "\n")));
				
				}

			}

			/*
			** increment
			*/

			head = head->next;

		}

	}

	/*
	** username not set
	*/

	return (ft_uerror("$[server]: you have not set a username, set with /nick <name>\n"));

}