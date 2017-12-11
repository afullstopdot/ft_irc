/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

static char	*ft_build_message(char *sender, char **msg)
{

	char	**tmp;
	char	*resp;

	/*
	** start from 2 cause argv [/msg <nick> <msg>]
	*/

	tmp = msg + 2;

	/*
	** default
	*/

	if (sender && tmp && (resp = ft_strdup("$[")))
	{

		/*
		** Join username
		*/
printf("%s\n",sender);
		if ((resp = ft_strjoin(resp, ft_strjoin(sender, "]: "))))
		{

			/*
			** Attach msg, start from 2 cause argv [/msg <nick> <msg>]
			*/

			// while (*tmp)
			// {

			// 	/*
			// 	** join, on fail exit
			// 	*/

			// 	resp = ft_strjoin(resp, *tmp);
				
			// 	/*
			// 	** Next
			// 	*/

			// 	tmp++;

			// }

			/*
			** return message
			*/

			return (ft_resp(C_GRN, resp));

		}

	}

	return (NULL);

}

/*
** Send message (temporary)
*/

char		*ft_send_message(t_env *env, char **argv, int c_index)
{

	t_user	*user;
	t_user	*user2;
	char	*msg;

	/*
	** Find our user
	*/

	if ((user = ft_find_user_by_key(env, c_index)))
	{

		/*
		** Check if connected on a channel, if so find users on said channel
		*/

		if (user->curr_channel && user->curr_channel->users)
		{

			/*
			** Find the client we want to message
			*/

			if ((user2 = ft_find_user_by_key(env, ft_find_user_by_name(user->curr_channel->users, argv[1]))))
			{

				/*
				** Build message to send to user
				*/

				if ((msg = ft_build_message(user2->nick, argv)))
				{


					/*
					** Send message
					*/

					ft_writen(env->client[user2->c_index], msg, ft_strlen(msg));

					/*
					** sent
					*/

					return ft_resp(C_GRN, "$[server]: message sent!\n");

				}
				else
					return ft_resp(C_RED, "$[server]: ufailed to build message\n");

			}
			else
				return ft_resp(C_RED, "$[server]: user does not exist\n");

		}
		else
			return ft_resp(C_RED, "$[server]: no users on channel\n");

	}
	else
		return ft_resp(C_RED, "$[server]: could not find you!\n");

}