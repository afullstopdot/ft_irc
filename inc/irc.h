/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRC_H
# define IRC_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <errno.h> //remove on production
# include <libft.h>

/*
** TRUE / FALSE constants
*/

#ifndef TRUE
	# define TRUE 1
#endif
#ifndef FALSE
	# define FALSE 0
#endif

/*
** Colors
*/

# define C_RED "\x1B[31m"
# define C_GRN "\x1B[32m"
# define C_YEL "\x1B[33m"
# define C_BLU "\x1B[34m"
# define C_MAG "\x1B[35m"
# define C_CYN "\x1B[36m"
# define C_WHT "\x1B[37m"
# define C_RST "\x1B[0m"

/*
** shortens all the typecasts of pointer arguments
*/

# define	SA struct sockaddr

/*
** Usage & Error prototypes for (client & server)
*/

void                    ft_fatal_error(char *msg);
void                    ft_dump_usage(void);

/*
** Wrappers
*/

void					ft_bind(int fd, const struct sockaddr *sa, socklen_t salen);
void					ft_listen(int fd, int backlog);
int						ft_accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
int						ft_socket(int domain, int type, int protocol);
int						ft_select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
ssize_t					ft_read(int fd, void *ptr, size_t nbytes);
void					ft_writen(int fd, void *ptr, size_t nbytes);
void					ft_close(int fd);

#endif
