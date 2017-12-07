/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channels.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** Create a channel if it does not exists
*/

void			ft_channel_create(t_env *env, char *name)
{

	t_channels	*head;
	t_channels	*new;

	/*
	** assign current list of channels
	*/

	head = env->channels;

	/*
	** Check if a channel with this name exists
	*/

	while (head)
	{

		if (ft_strequ(head->name, name))
			return ;

		head = head->next;
	}

	/*
	** if we get here its because the channel does not exist
	*/

	if ((new = (t_channels *)malloc(sizeof(t_channels))))
	{

		/*
		** assign channel name
		*/

		new->name = ft_strdup(name);

		/*
		** list of users connected to the channel
		*/

		new->users = NULL;

		/*
		** add to front of channels
		*/

		new->next = env->channels;

		/*
		** point to start
		*/

		env->channels = new;

	}
	else
		ft_fatal_error("failed to malloc --dead");

}

/*
** Join a channel
*/

char			*ft_channel_join(t_env *env, char **argv, int c_index)
{

	t_user		*head;
	t_user		*new;

	/*
	** create the channel (if it doesnt exist)
	*/

	ft_channel_create(env, argv[1]);

	/*
	** assign from list of users (we want to find our {} and point to it)
	*/

	if ((head = env->users))
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
				** create a new t_user for channels though
				*/

				if ((new = (t_user *)malloc(sizeof(t_user))))
				{

					/*
					** copy the nickname over
					*/

					ft_strcpy(new->nick, head->nick);

					/*
					** assign the index in the client array
					*/

					new->c_index = head->c_index;

					/*
					** set next as the current head of channels user
					*/

					new->next = env->channels->users;

					/*
					** make channels head point to new user
					*/

					env->channels->users = new->next;

					/*
					** Update current channel
					*/

					head->curr_channel = env->channels;

					/*
					** exit
					*/

					return (ft_resp(C_GRN, "$[server]: successfully joined channel\n"));

				}
				else
					ft_fatal_error("failed to malloc --dead");

			}

			head = head->next;

		}

	}
	else
		ft_fatal_error("no users available");

	/*
	** did not join the channel
	*/

	return (ft_resp(C_RED, "$[server]: failed to join the channel\n"));

}

/*
** List users on channel
*/

char 			*ft_channel_list(t_env *env, int c_index)
{

	t_user		*head;

	head = env->users;

	while (head)
	{

		if (head->c_index == c_index)
		{

			t_user	*tmp = head->curr_channel->users;

			while (tmp)
			{

				printf("/u/%s\n", tmp->nick);
				tmp = tmp->next;

			}

		}

		head = head->next;

	}

	return (ft_strdup("tsek"));

}