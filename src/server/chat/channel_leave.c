/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel_leave.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** Leave a channel
*/

char			*ft_channel_leave(t_env **env, char **argv, int c_index)
{

	t_channels	*channels;

	/*
	** Find all the channels the user is a part of, and remove him from them
	*/

	if ((channels = (*env)->channels))
	{

		/*
		** Loop through all the channels
		*/

		while (channels && channels->name)
		{

			/*
			** Find channel by name
			*/

			if (ft_strequ(channels->name, argv[1]))
			{

				/*
				** All the users on this channel
				*/

				ft_delete_user(&channels->users, c_index);

				/*
				** exit
				*/

				return (ft_resp(C_GRN, "$[server]: left channel\n"));

			}

			/*
			** Increment counter
			*/

			channels = channels->next;

		}

	}

	return (ft_resp(C_RED, "$[server]: no channels exist\n"));

}