# include <client.h>

/*
** Initialize values for select
*/

void		ft_init_select(t_cli *env)
{

	int 	i;
	t_node	*node;

	/*
	** counter
	*/

	i = 1;

	/*
	** maxfd + 1 is the current value of the first argument to select(2)
	*/

	env->maxfd = env->listenfd;

	/*
	** the highest index in the client array that is currently in use (by default STDIN)
	*/

	env->maxi = 0;

	/*
	** Add listenfd (STDIN)
	*/

	env->client[0] = env->listenfd;

	/*
	** initialize clients --
	*/

	while (i < FD_SETSIZE)
	{

		/*
		** -1 indicates available entry
		*/

		env->client[i] = -1;

		/*
		** increment counter
		*/

		i++;

	}

	/*
	** Create node for reading/writing STDIN
	*/

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		ft_fatal_error("unable to allocate meory");

	/*
	** Initialize buffers
	*/

	ft_cbuf_init(&node->rbuf);
	ft_cbuf_init(&node->wbuf);

	/*
	** Push to list of nodes in the client env
	*/

	node->next = env->nodes;
	env->nodes = node;

}