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
** Nodes to read and write to
*/

typedef struct 			s_node
{

	/*
	** Read Circular buffer
	*/

	struct s_cbuf 		rbuf;

	/*
	** Write Circular buffer
	*/

	struct s_cbuf 		wbuf;

	/*
	** next node
	*/

	struct s_node		*next;

}						t_node;

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

	/*
	** Client fd
	*/

	int 				listenfd;

	/*
	** maxfd + 1 is the current value of the first argument to select(2)
	*/

	int					maxfd;

	/*
	** The highest index in the client array that is currently in use
	*/

	int					maxi;

	/*
	** All the fds, client needs to write to
	*/

	int					client[FD_SETSIZE];

	/*
	** read set
	*/

	fd_set				rset;

	/*
	** write set
	*/

	fd_set				wset;

	/*
	** Nodes of fd to read/write to
	*/

	struct s_node 		*nodes;

}						t_cli;

/*
** return the IPv4 address of a DNS
*/

char                	*ft_resolve_host(char *argv);

/*
** Connect the client to the server
*/

void 					ft_connect_to_server(t_cli **env, char **argv);

/*
** Wrapper for ft_connect_to_server
*/

char					*ft_wconnect_to_client(t_cli **env, char **argv);

/*
** Wrapper for connecting to client
*/

void 					ft_wconnect(t_cli *env, char **argv);

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

/*
** Send msg to server
*/

char					*ft_send_to_server(t_cli **env, char *buf);

/*
** write to fd
*/

void					ft_send_response(char *buff, int connfd);

/*
** Initialize values for select
*/

void					ft_init_select(t_cli *env);

/*
** Check all clients for data
** Final version should use rotary buffers and not char pointers
*/

void					ft_check_client(t_cli **env, int *nready);

/*
** Main loop for handling clients simulantaneously
*/

void					ft_main_loop(t_cli *env);

#endif