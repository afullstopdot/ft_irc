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

/*
** Build the message to send to the user, mem leaks all over
*/

char		*ft_build_message(char *sender, char **message)
{

	char	*resp;
	char	*temp;

	/*
	** Add sender to message
	*/

	if ((resp = ft_strjoin("$[", ft_strjoin(sender, "]: "))))
	{

		/*
		** Add message
		*/

		while (*message)
		{

			temp = ft_strjoin(*message, " ");
			resp = ft_strjoin(resp, temp);
			message++;

		}

		resp = ft_strtrim(resp);
		resp = ft_strjoin(resp, "\n");

	}
	return (ft_resp(C_CYN, resp));

}

/*
** Send message (temporary)
** env - server environment
** argv - message the user is trying to send to someone [/msg <nickname> "hi" "there"]
** c_index - the index of the user in the env->client array
** format - [msg from <nickname>]: Hi There
*/

char		*ft_send_message(t_env **env, char **argv, int c_index)
{

	/*
	** User thats sending the message
	*/

	t_user	*sender;

	/*
	** User thats sending the message
	*/

	t_user	*reciever;

	/*
	** Built message
	*/

	char	*msg;

	/*
	** Count
	*/

	int 	count;

	/*
	** Initialize count
	*/

	count = 0;

	/*
	** Find the user by using the client index unique to the user
	*/

	if ((sender = ft_find_user_by_key(env, c_index)))
	{

		/*
		** Nickname needs to be set
		*/

		if (!ft_strlen(sender->nick))
			return (ft_resp(C_RED, "$[server]: username must be set before joining a channel\n"));

		/*
		** Find the client to send the message to
		*/

		if ((reciever = ft_find_user_by_name(env, argv[1])))
		{

			/*
			** Build the message to send to the user
			*/

			if ((sender->c_index != reciever->c_index) && (msg = ft_build_message(sender->nick, argv + 2)))
			{

				/*
				** write into the wbuf
				*/

				while (msg[count])
				{
					/*
					** Only add to the queue if there is no space (this circular buffer does not overlap)
					** If there is no more space, exit the loop
					*/

					if (!ft_cbuf_full(&(*env)->users[reciever->c_index].wbuf))
					{

						/*
						** Add character to the queue
						*/

						ft_cbuf_put(&(*env)->users[reciever->c_index].wbuf, msg[count]);

					}
					else
						break ;

					/*
					** Increment pointer
					*/

					count++;

				}

				/*
				** Indicate to the user that the message was sent
				*/

				return (ft_resp(C_GRN, "$[server]: message sent!\n"));

			}

			return (ft_resp(C_RED, "$[server]: message not sent!\n"));

		}

		/*
		** Could not find our reciever
		*/

		return (ft_resp(C_RED, "$[server]: could not find said user!\n"));

	}

	/*
	** Could not find our user
	*/

	return (ft_resp(C_RED, "$[server]: could not find you!\n"));

}