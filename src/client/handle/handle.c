# include <client.h>

/*
** Handle the user input
*/

char		*ft_handle(t_cli *env, char *buf)
{

	char	**argv;
	char	*resp;
	int 	count;

	resp = NULL;
	count = 0;

	/*
	** break recieved buffer to check if valid command > execute
	*/

	if (buf && (argv = ft_strsplit(buf, ' ')) && ft_dstrlen(argv) > 0)
	{

		/*
		** Connect to a server [/connect server port]
		*/

		if ((ft_strequ(ft_strtrim(argv[0]), "/connect") && argv[1] && argv[2]) || !env->connected)
		{

			if (ft_strequ(ft_strtrim(argv[0]), "/connect"))
				resp = ft_wconnect_to_client(&env, argv);
			else if (!env->connected && !ft_strequ(ft_strtrim(argv[0]), "/connect"))
				resp = ft_resp(C_YEL, "$[client]: you are not connected to the server\n");

			while (resp[count])
			{

				if (!ft_cbuf_full(&env->nodes[0].wbuf))
				{

					/*
					** Add character to the queue
					*/

					ft_cbuf_put(&env->nodes[0].wbuf, resp[count]);

				}
				else
					break ;
				count++;
			}

			env->nodes[0].wbuf.done = TRUE;

			ft_cbuf_flush(&env->nodes[0].rbuf, TRUE);

			ft_strdel(&resp);


		}
		else
		{

			if (env->nodes[1].rbuf.done)
			{

				while (env->nodes[1].rbuf.buf[count])
				{
					if (!ft_cbuf_full(&env->nodes[0].wbuf))
					{

						/*
						** Add character to the queue
						*/

						ft_cbuf_put(&env->nodes[0].wbuf, env->nodes[1].rbuf.buf[count]);

					}
					else
						break ;
					count++;
				}

				if (!ft_cbuf_full(&env->nodes[0].wbuf))
				{

					/*
					** Add character to the queue
					*/

					ft_cbuf_put(&env->nodes[0].wbuf, '\n');

				}
				env->nodes[0].wbuf.done = TRUE;
				ft_cbuf_flush(&env->nodes[1].rbuf, TRUE);

			}
			else if (!env->nodes[1].wbuf.done)
			{
				while (env->nodes[0].rbuf.buf[count])
				{
					if (!ft_cbuf_full(&env->nodes[1].wbuf))
					{

						/*
						** Add character to the queue
						*/

						ft_cbuf_put(&env->nodes[1].wbuf, env->nodes[0].rbuf.buf[count]);

					}
					else
						break ;
					count++;
				}

				if (!ft_cbuf_full(&env->nodes[1].wbuf))
				{

					/*
					** Add character to the queue
					*/

					ft_cbuf_put(&env->nodes[1].wbuf, '\n');

				}
				env->nodes[1].wbuf.done = TRUE;
				ft_cbuf_flush(&env->nodes[0].rbuf, TRUE);	
			}
		
		}
		
	}

	return (NULL);

}