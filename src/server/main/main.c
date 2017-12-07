/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

int				main(int argc, char **argv)
{

	int					i;
	int					maxi;
	int					maxfd;
	int					listenfd;
	int					connfd;
	int					sockfd;
	int					nready;
	int					client[FD_SETSIZE];
	size_t				n;
	fd_set				rset;
	fd_set				allset;
	char				buf[MAXLINE];
	socklen_t			clilen;
	struct sockaddr_in	cliaddr;
	struct sockaddr_in	servaddr;

	if (argc != 2)
		ft_dump_usage();

	listenfd = ft_socket(AF_INET, SOCK_STREAM, 0);
	ft_bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(ft_atoi(argv[1]));
	ft_bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
	ft_listen(listenfd, LISTENQ);
	maxfd = listenfd;
	maxi = -1;
	for (i = 0; i < FD_SETSIZE; i++)
	{
		client[i] = -1;
	}
	FD_ZERO(&allset);
	FD_SET(listenfd, &allset);
	for ( ; ; )
	{
		rset = allset;
		nready = ft_select(maxfd + 1, &rset, NULL, NULL, NULL);
		if (FD_ISSET(listenfd, &rset))
		{

			clilen = sizeof(cliaddr);
			connfd = ft_accept(listenfd, (SA *) &cliaddr, &clilen);
			printf("New client connected\n");

			for (i = 0; i < FD_SETSIZE; i++)
			{

				if (client[i] < 0) {
					client[i] = connfd;
					break;
				}

			}

			if (i == FD_SETSIZE)
				ft_fatal_error("server cannot handle any more clients");

			FD_SET(connfd, &allset);
			if (connfd > maxfd)
				maxfd = connfd;
			if (i > maxi)
				maxi = i;
			if (--nready <= 0)
				continue;

		}
		
		for (i = 0; i <= maxi; i++)
		{
			if ((sockfd = client[i]) < 0)
				continue ;
			if (FD_ISSET(sockfd, &rset))
			{
				if ((n = ft_read(sockfd, buf, MAXLINE)) == 0)
				{
					printf("connection closed\n");
					ft_close(sockfd);
					FD_CLR(sockfd, &allset);
					client[i] = -1;
				}
				else{
					ft_writen(sockfd, buf, n);
				}

				if (--nready <= 0)
					break;
			}

		}

	}

	
    return (0);
}
