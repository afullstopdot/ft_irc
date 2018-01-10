/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** Check if we are connected on a channel
*/

static int 		ft_connected(t_user *users, int c_index)
{

	t_user		*temp;

	temp = users;

	/*
	** run through all the users
	*/

	while (temp)
	{

		/*
		** Check if we are on this channel
		*/

		if (temp->c_index == c_index)
			return (TRUE);

		/*
		** Increment
		*/

		temp = temp->next;

	}

	/*
	** not connected
	*/

	return (FALSE);

}

/*
** Join a channel
*/

char			*ft_channel_join(t_env **env, char **argv, int c_index)
{

	t_user		*head;
	t_channels	*channel;
	t_user		*user;

	/*
	** create the channel (if it doesnt exist)
	*/

	ft_channel_create(env, argv[1]);

	/*
	** assign from list of users (we want to find our {} and point to it)
	*/

	if ((head = (*env)->users))
	{

		/*
		** Find user {}
		*/

		while (head)
		{

			/*
			** check if right user
			*/

			if (head->c_index == c_index)
			{

				/*
				** Nickname needs to be set
				*/

				if (!ft_strlen(head->nick))
					return (ft_resp(C_RED, "$[server]: username must be set before joining a channel\n"));

				/*
				** create a new t_user for channels though NB-- ADD A CHECK TO SEE IF THE USER IS ALREADY APART OF THE CHANNEL
				*/

				if ((user = (t_user *)malloc(sizeof(t_user))))
				{

					/*
					** Find the channel we want to join by name
					*/

					channel = (*env)->channels;

					/*
					** loop through list
					*/

					while (channel)
					{

						/*
						** When we find out channel break, we will use it later
						*/

						if (ft_strequ(argv[1], channel->name))
							break ;

						/*
						** increment
						*/

						channel = channel->next;

					}

					/*
					** Check that we are'nt already connected on this channel
					*/

					if (!ft_connected(channel->users, c_index))
					{

						/*
						** copy the nickname over
						*/

						ft_strcpy(user->nick, head->nick);

						/*
						** assign the index in the client array
						*/

						user->c_index = head->c_index;

						/*
						** set next as the current head of channels user
						*/

						user->next = channel->users;

						/*
						** make channels head point to new user
						*/

						channel->users = user;

						/*
						** Update current channel
						*/

						head->curr_channel = channel;

						/*
						** exit
						*/

						return (ft_resp(C_GRN, "$[server]: successfully joined channel\n"));
					
					}
					else
						return (ft_resp(C_RED, "$[server]: you are already connect on this channel\n"));

				}
				else
					ft_fatal_error("failed to malloc --dead");

				break ;

			}

			/*
			** Increment
			*/

			head = head->next;

		}

	}
	else
		return (ft_resp(C_RED, "$[server]: no users available to join the channel\n"));

	/*
	** did not join the channel
	*/

	return (ft_resp(C_RED, "$[server]: failed to join the channel\n"));

}