# include <server.h>

/*
** Create a channel if it does not exists
*/

void			ft_channel_create(t_env **env, char *name)
{

	t_channels	*head;
	t_channels	*new;

	/*
	** assign current list of channels
	*/

	head = (*env)->channels;

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

		new->next = (*env)->channels;

		/*
		** point to start
		*/

		(*env)->channels = new;

	}
	else
		ft_fatal_error("failed to malloc --dead");

}