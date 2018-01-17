# include <client.h>

/*
** Connect the client to the server
*/

void 					ft_connect_to_server(t_cli *env, char **argv)
{
	struct sockaddr_in	servaddr;
	char				*ip_addr;
	int					sockfd;

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

	env->servfd = sockfd;

	/*
	** Update connected
	*/

	env->connected = TRUE;

	/*
	** return
	*/

	return ;

}