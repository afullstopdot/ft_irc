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
# include <errno.h> //remove on submission
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

# define SA struct sockaddr

/*
** maximum length of a nickname
*/

# define NICKNAME_MAX 9

/*
** max text line length
*/

# define MAXLINE 4096

/*
** buffer size for reads and writes
*/

# define BUFFSIZE 8192

/*
** To make for easier type casting
*/

# define SA struct sockaddr

/*
** Circular buffer
*/

typedef struct 			s_cbuf
{

	/*
	** This is the managed buffer. The size of this buffer BUFFSIZE
	*/

	char 				buf[BUFFSIZE];

	/*
	** This is the head index. 
	** The incoming bytes get written to the managed buffer using this index
	*/

	int 				head;

	/*
	** This index is used to retrieve the oldest data in the queue
	*/

	int 				tail;

	/*
	** This field is used to keep track of the total number 
	** of elements currently in the queue
	*/

	int 				count;

	/*
	** Done reading/writing
	*/

	int 				done;

}						t_cbuf;

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
void					ft_connect(int fd, const struct sockaddr *sa, socklen_t salen);
int						ft_accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
int						ft_socket(int domain, int type, int protocol);
int						ft_select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
void					ft_writen(int fd, void *ptr, size_t nbytes);
void					ft_close(int fd);
char					*ft_wreadline(int fd);

/*
** Initialize the circular buffer queue
*/

void  					ft_cbuf_init(t_cbuf *buf);

/*
** Determine whether or not the circular buffer queue is empty
*/

int 					ft_cbuf_empty(t_cbuf *buf);

/*
** Determine whether or not the circular buffer queue is full
*/

int   					ft_cbuf_full(t_cbuf *buf);

/*
** Get a byte from the queue (TAIL)
*/

int   					ft_cbuf_get(t_cbuf *buf);

/*
** Put a byte to the circular buffer queue (HEAD)
*/

void  					ft_cbuf_put(t_cbuf *buf, const char c);

/*
** Flush the queue and optionally clear the buffer bytes to 0
*/

void  					ft_cbuf_flush(t_cbuf *buf, const int clearBuffer);

/*
** Modulo for circular buffer
*/

unsigned int 			ft_modulo_inc(const unsigned int value, const unsigned int modulus);
unsigned int 			ft_modulo_dec(const unsigned int value, const unsigned int modulus);

/*
** Read into the circular buffer
*/

ssize_t					ft_read(int fd, t_cbuf *buf, size_t nbytes);

/*
** color message
*/

char					*ft_resp(char *start, char *msg);

/*
** invalid command
*/

char					*ft_invalid_command(void);

#endif
