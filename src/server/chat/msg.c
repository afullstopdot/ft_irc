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
	** Find the user by using the client index unique to the user
	*/

	if ((sender = ft_find_user_by_key(env, c_index)))
	{

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
				** copy into env instead of {} returned so wbuf is updated in memory
				*/

				ft_strclr((*env)->users[reciever->c_index].wbuf);
				ft_strcpy((*env)->users[reciever->c_index].wbuf, msg);

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