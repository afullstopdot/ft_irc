/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_client.c                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** Remove client from array and set
*/

void		ft_remove_client(t_env **env, int sockfd, int index)
{
	t_user	*head;

	/*
	** Show which user has disconnected from the chat
	*/

	if ((head = (*env)->users))
	{

		/*
		** Loop through head
		*/

		while (head)
		{

			/*
			** Find user by client index
			*/

			if (head->c_index == index)
			{

				/*
				** dump error message
				*/

				printf("%s has disconnected from the chat\n", ft_strlen(head->nick) ? head->nick : "unknown user");

			}

			/*
			** increment pointer
			*/

			head = head->next;

		}

	}

	/*
	** close sockfd
	*/

	ft_close(sockfd);

	/*
	** Remove fd from both select sets
	*/

	FD_CLR(sockfd, &(*env)->wset);
	FD_CLR(sockfd, &(*env)->rset);

	/*
	** open space in array
	*/

	(*env)->client[index] = -1;

	/*
	** remove from user/channels list
	*/

	ft_remove_user(env, index);

}