# include <client.h>

/*
** Save new client
*/

void	ft_save_fd(t_cli **env, int connfd)
{

	int	i;
	t_node	*node;

	/*
	** counter variable
	*/

	i = 0;

	/*
	** Save new client descriptor
	*/

	while (i < FD_SETSIZE)
	{

		/*
		** If position is available (will have a value of -1 if available)
		*/

		if ((*env)->client[i] < 0)
		{

			/*
			** Save file descriptor on first available position
			*/

			(*env)->client[i] = connfd;

			/*
			** Done saving, break
			*/

			break ;

		}
		i++;

	}

	/*
	** Check that we still have space for new clients after trying to save new client
	*/

	if (i == FD_SETSIZE)
		ft_fatal_error("client cannot handle more fd");

	/*
	** Assign for select
	*/

	if (connfd > (*env)->maxfd)
		(*env)->maxfd = connfd;

	/*
	** Max index in client aaray
	*/

	if (i > (*env)->maxi)
		(*env)->maxi = i;

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

	node->next = (*env)->nodes;
	(*env)->nodes = node;

}

/*
** Connect the client to the server
*/

void 					ft_connect_to_server(t_cli **env, char **argv)
{
	struct sockaddr_in	servaddr;
	char				*ip_addr;
	int					sockfd;

	/*
	** If we are connected already return
	*/

	if ((*env)->connected)
		return ;

	/*
	** resolve host IP
	*/

	ip_addr = ft_resolve_host(argv[1]);

	/*
	** open socket for tcp
	*/

	sockfd = ft_socket(AF_INET, SOCK_STREAM, 0);

	/*
	** set server address
	*/

	ft_set_sockaddr((SA *) &servaddr, AF_INET, ft_atoi(argv[2]), inet_addr(ip_addr));

	/*
	** dont need resolved host IP anymore
	*/

	ft_strdel(&ip_addr);

	/*
	** establish a connection with a TCP server
	*/

	ft_connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

	/*
	** Assign sockfd to client env
	*/

	(*env)->servfd = sockfd;

	/*
	** Update connected
	*/

	(*env)->connected = TRUE;

	/*
	** Add server to rset
	*/

	ft_save_fd(env, sockfd); //temp function in this structure

	/*
	** return
	*/

	return ;

}

/*
** Wrapper for connecting to client
*/

void 					ft_wconnect(t_cli *env, char **argv)
{

	/*
	** Connect the client to the server
	*/

	ft_connect_to_server(&env, argv);

}