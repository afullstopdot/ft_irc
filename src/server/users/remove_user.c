# include <server.h>

/*
** remove a client from users/channels linked list, before closing connection
*/

void			ft_remove_user(t_env **env, int c_index)
{

	t_channels	*channels;

	/*
	** Find our user by client index, and remove from list
	*/

	ft_delete_user(&(*env)->users, c_index);

	/*
	** Find all the channels the user is a part of, and remove him from them
	*/

	if ((channels = (*env)->channels))
	{

		/*
		** Loop through all the channels
		*/

		while (channels)
		{

			/*
			** All the users on this channel
			*/

			ft_delete_user(&channels->users, c_index);

			/*
			** Increment counter
			*/

			channels = channels->next;

		}
	}


}