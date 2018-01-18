# include <server.h>

/*
** Check all clients for data
** Final version should use rotary buffers and not char pointers
*/

void		ft_check_client(t_env **env, int *nready)
{

	int		i;
	int		count;
	int		sockfd;
	size_t	n;
	char	*resp;
	t_user *user;

	user = (*env)->users;

	/*
	** counter
	*/

	i = 0;
	count = 0;

	/*
	** Check for fd in sets that can be read from
	*/

	for (i = 0; i <= (*env)->maxi; i++)
	{

		/*
		** Check if a valid fd
		*/

		if ((sockfd = (*env)->client[i]) < 0)
			continue ;

		/*
		** Check if the FD is in the set returned by select
		*/

		if (FD_ISSET(sockfd, &(*env)->rset))
		{

			/*
			** Read from client
			*/

			if ((n = ft_read(sockfd, &(*env)->users[i].rbuf, MAXLINE)) == 0)
			{

				/*
				** remove client
				*/

				ft_remove_client(&(*env), sockfd, i);

			}
			else
			{

				/*
				** Handle command
				*/

				if (user[i].rbuf.done)
				{

					/*
					** Handle the command in the buf
					*/

					resp = ft_handle_command(&(*env), user[i].rbuf.buf, i);

					/*
					** write into the wbuf
					*/

					while (resp[count])
					{
						/*
						** Only add to the queue if there is no space (this circular buffer does not overlap)
						** If there is no more space, exit the loop
						*/

						if (!ft_cbuf_full(&user[i].wbuf))
						{

							/*
							** Add character to the queue
							*/

							ft_cbuf_put(&user[i].wbuf, resp[count]);

						}
						else
							break ;

						/*
						** Increment pointer
						*/

						count++;

					}

					count = 0;

					/*
					** Free up some memory
					*/

					ft_strdel(&resp);

					/*
					** Clear our rbuf now
					*/

					ft_cbuf_flush(&user[i].rbuf, TRUE);

				}

			}

			if (--(*nready) <= 0)
				break;
		}

		/*
		** Check if we can write to fd
		*/

		if (FD_ISSET(sockfd, &(*env)->wset))
		{

			/*
			** Write to current user
			*/

			ft_writen(sockfd, (char *)user[i].wbuf.buf, user[i].wbuf.count);

			/*
			** Clear our rbuf now
			*/

			ft_cbuf_flush(&user[i].wbuf, TRUE);

			if (--(*nready) <= 0)
				break;
		}

	}

}