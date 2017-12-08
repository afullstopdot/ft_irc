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
** Send message (temporary)
*/

char		*ft_send_message(t_env *env, char **argv, int c_index)
{

	int		client_index;
	t_user	*head;

	head = env->users;
	while (head)
	{

		if (head->curr_channel && head->c_index == c_index)
		{

			/*
			** Find the client by username
			*/

			client_index = ft_get_client(head->curr_channel->users, argv[1]);

			/*
			** send message
			*/

			ft_writen(env->client[client_index], argv[2], ft_strlen(argv[2]));

		}

		head = head->next;

	}
	/*
	** Find the client by username
	*/

	return ft_resp(C_GRN, "sent\n");

}