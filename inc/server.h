/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <sys/select.h>

/*
** header with prototypes, headers and constants used by both server & client
*/

# include <irc.h>

/*
** 2nd argument to listen()
*/

# define LISTENQ 1024

/*
** max text line length
*/

#define	MAXLINE	4096

/*
** buffer size for reads and writes
*/

#define	BUFFSIZE 8192

/*
** Circular buffer
*/

typedef struct 			ringBufS
{

	/*
	** This is the managed buffer. The size of this buffer BUFFSIZE
	*/

	unsigned char 		buf[BUFFSIZE];

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

}						ringBufS;

/*
** User information
*/

typedef struct 			s_user
{

	/*
	** user nickname, empty by default
	*/

	char				nick[NICKNAME_MAX];

	/*
	** index in client
	*/

	int 				c_index;

	/*
	** Current channel
	*/

	struct s_channels	*curr_channel;

	/*
	** Circular buffers
	*/

	struct ringBufS 	*rbuf;
	struct ringBufS 	*wbuf;

	/*
	** Next
	*/

	struct s_user		*next;

}						t_user;

/*
** Channels on server
*/

typedef struct 			s_channels
{

	/*
	** Channel name
	*/

	char				*name;

	/*
	** Users on this channel
	*/

	struct s_user 		*users;

	/*
	** List
	*/

	struct s_channels	*next;

}						t_channels;

/*
** Server environment
*/

typedef struct			s_env
{

	/*
	** Server port
	*/

	int					port;

	/*
	** Server listenfd
	*/

	int					listenfd;

	/*
	** maxfd + 1 is the current value of the first argument to select(2)
	*/

	int					maxfd;

	/*
	** The highest index in the client array that is currently in use
	*/

	int					maxi;

	/*
	** As clients arrive, record their connected socket descriptor
	** in the first available entry of the array
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
	** list of users of type t_user {}
	*/

	struct s_user		*users;

	/*
	** channels
	*/

	struct s_channels	*channels;

}						t_env;

/*
** Initialize server port
*/

void					ft_init_server_port(int argc, char **argv, t_env *env);

/*
** Create a server
*/

void					ft_create_server(int argc, char **argv, t_env **env);

/*
** Initialize values for select
*/

void					ft_init_select(t_env **env);

/*
** Main loop for handling clients simulantaneously
*/

void					ft_main_loop(t_env **env);

/*
** Save new client
*/

void					ft_save_client(t_env **env, int connfd);

/*
** Accept a new client (if there are any)
*/

int						ft_accept_client(t_env **env);

/*
** Check all clients for data
*/

void					ft_check_client(t_env **env, int *nready);

/*
** Remove client from array and set
*/

void					ft_remove_client(t_env **env, int sockfd, int index);

/*
** Create a new user and add to list
*/

void					ft_create_user(t_env **env, int c_index);

/*
** Handle commands
*/

char					*ft_handle_command(t_env **env, char *buf, int c_index);

/*
** set username
*/

char					*ft_set_username(t_env **env, char **argv, int c_index);

/*
** get username
*/

char					*ft_get_username(t_env **env, int c_index);

/*
** invalid command
*/

char					*ft_invalid_command(void);

/*
** success msg
*/

char					*ft_usuccess(char *msg);

/*
** error msg
*/

char					*ft_uerror(char *msg);

/*
** color message
*/

char					*ft_resp(char *start, char *msg);

/*
** Create a channel if it does not exists
*/

void					ft_channel_create(t_env **env, char *name);

/*
** join a channel
*/

char					*ft_channel_join(t_env **env, char **argv, int c_index);

/*
** list all users on a channel
*/

char 					*ft_channel_list(t_env **env, int c_index);

/*
** remove a client from linked list, before closing connection
*/

void					ft_remove_user(t_env **env, int c_index);

/*
** Given a reference to the head of a list
** and a key, delete a node
*/

void					ft_delete_user(t_user **head, int key);

/*
** Leave a channel
*/

char					*ft_channel_leave(t_env **env, char **argv, int c_index);

/*
** Send message
*/

char					*ft_send_message(t_env **env, char **argv, int c_index);

/*
** Find a user key by name from a channel
*/
t_user					*ft_find_user_by_name(t_env **env, char *name);

/*
** Find a user by key
*/

t_user					*ft_find_user_by_key(t_env **env, int c_index);

/*
** Initialize the circular buffer queue
*/

void  					ringBufS_init(ringBufS *_this);

/*
** Determine whether or not the circular buffer queue is empty
*/

int 					ringBufS_empty(ringBufS *_this);

/*
** Determine whether or not the circular buffer queue is full
*/

int   					ringBufS_full(ringBufS *_this);

/*
** Get a byte from the queue (TAIL)
*/

int   					ringBufS_get(ringBufS *_this);

/*
** Put a byte to the circular buffer queue (HEAD)
*/

void  					ringBufS_put(ringBufS *_this, const unsigned char c);

/*
** Flush the queue and optionally clear the buffer bytes to 0
*/

void  					ringBufS_flush(ringBufS *_this, const int clearBuffer);

/*
** Modulo for circular buffer
*/

unsigned int 			modulo_inc(const unsigned int value, const unsigned int modulus);
unsigned int 			modulo_dec(const unsigned int value, const unsigned int modulus);
ssize_t					ft_read(int fd, ringBufS *_this, size_t nbytes);

#endif