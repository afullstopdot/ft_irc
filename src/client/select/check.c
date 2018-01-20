# include <client.h>

/*
** Check all clients for data
** Final version should use rotary buffers and not char pointers
*/

void		ft_check_client(t_cli **env, int *nready)
{

	int		i;
	int		sockfd;
	size_t	n;

	/*
	** counter
	*/

	i = 0;

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

			if ((n = ft_read(sockfd, &(*env)->nodes[i].rbuf, BUFFSIZE)) == 0)
			{

				/*
				** remove client
				*/

				ft_fatal_error("connection to server closed");

			}
			else
			{

				if ((*env)->nodes[i].rbuf.done)
				{

					ft_handle((*env), (*env)->nodes[i].rbuf.buf);

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

			ft_writen(sockfd, (*env)->nodes[i].wbuf.buf, (*env)->nodes[i].wbuf.count);

			/*
			** Clear our rbuf now
			*/

			ft_cbuf_flush(&(*env)->nodes[i].wbuf, TRUE);

			if (--(*nready) <= 0)
				break;
		}

	}

}