/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/select.h>

/*
** header with prototypes, headers and constants used by both server & client
*/

# include <irc.h>
# include <netdb.h>

/*
** Client environment
*/

typedef struct 			s_cli
{

	/*
	** States if the client connected to the server
	*/

	int					connected;

	/*
	** Server fd
	*/

	int					servfd;

}						t_cli;

/*
** return the IPv4 address of a DNS
*/

char                	*ft_resolve_host(char *argv);

/*
** Connect the client to the server
*/

void 					ft_connect_to_server(t_cli *env, char **argv);

/*
** Wrapper for ft_connect_to_server
*/

char					*ft_wconnect_to_client(t_cli *env, char **argv);

/*
** Fill socket address
*/

void					ft_set_sockaddr(struct sockaddr *sa, int family, int port, in_addr_t address);

/*
** Initialize the client env
*/

void					ft_init_env(t_cli *env);

/*
** Handle the user input
*/

char					*ft_handle(t_cli *env, char *buf);

#endif