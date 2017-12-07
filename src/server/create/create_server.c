/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** Using the port number create a server (by creatinf a listening socket)
*/

void					ft_create_server(int argc, char **argv, t_env *env)
{

	struct sockaddr_in	servaddr;

	/*
	** Initialize server port
	*/

	ft_init_server_port(argc, argv, env);

	/*
	** Create a socket
	*/

	env->listenfd = ft_socket(AF_INET, SOCK_STREAM, 0);

	/*
	** Clear servaddr bits
	*/

	ft_bzero(&servaddr, sizeof(servaddr));

	/*
	** configure server addr info family
	*/

	servaddr.sin_family = AF_INET;

	/*
	** configure server addr address
	*/

	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	/*
	** Configure server port
	*/

	servaddr.sin_port = htons(env->port);

	/*
	** Bind server addr configure to socket
	*/

	ft_bind(env->listenfd, (SA *) &servaddr, sizeof(servaddr));

	/*
	** Listen for connections
	*/

	ft_listen(env->listenfd, LISTENQ);

	/*
	** Default users
	*/

	env->users = NULL;

}