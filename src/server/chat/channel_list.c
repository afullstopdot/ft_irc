# include <server.h>

/*
** Join name by ,
*/

static char 	*ft_join_name(char *src, const char *dst)
{

	char 		*tmp;

	tmp = NULL;
	if (src && dst)
	{

		/*
		** Join names by comma, remove.
		*/

		if ((tmp = ft_strjoin(dst, " ")))
		{

			if ((src = ft_strjoin(src, tmp)))
			{

				ft_strdel(&tmp);

				return (src);

			}

		}

	}

	return (ft_strdup("N/A"));

}

/*
** Clean resp
*/

static char 	*ft_clean_resp(char *src)
{

	char 		*tmp;

	/*
	** Check that src is not a NULL pointer
	*/

	if (src)
	{

		/*
		** clean trailing whitespace
		*/

		if (ft_strtrim(src))
		{

			/*
			** Add newline
			*/

			if ((tmp = ft_strjoin(src, "\n")))
			{

				/*
				** Delete dynamically allocated memory
				*/

				ft_strdel(&src);

				/*
				** add color
				*/

				if ((src = ft_resp(C_GRN, tmp)))
				{

					/*
					** delete dynamically allocated memory
					*/

					ft_strdel(&tmp);

					/*
					** return colored string
					*/

					return (src);

				}

				/*
				** Return fresh, clean resp
				*/

				return (tmp);

			}			

		}
	
	}

	return (ft_strdup("N/A"));

}

/*
** List users on channel
*/

char 			*ft_channel_list(t_env **env, int c_index)
{

	t_user		*head;
	t_user		*channel_users;
	char 		*resp;

	resp = ft_strdup("$[server]: ");

	/*
	** We want to find our user, only if there are actually users though
	*/

	if ((head = (*env)->users))
	{

		/*
		** Loop to find him
		*/

		while (head)
		{

			/*
			** found him by his client index
			*/

			if (head->c_index == c_index && head->curr_channel)
			{

				/*
				** Check if he has joined any channel currently 
				*/

				if ((channel_users = head->curr_channel->users))
				{

					/*
					** Find and join all the users
					*/

					while (channel_users)
					{

						/*
						** Join users to string
						*/

						resp = ft_join_name(resp, ft_strdup(channel_users->nick));

						/*
						** increment
						*/

						channel_users = channel_users->next;

					}

					/*
					** Clean response
					*/

					return (ft_clean_resp(resp));

				}
				else
					return (ft_resp(C_RED, "$[server]: you have not joined any channel\n"));

				/*
				** We found our client, exit if everything above failed
				*/

				break ;

			}

			head = head->next;

		}

	}
	else
		return (ft_resp(C_RED, "$[server]: no users exist\n"));

	return (ft_resp(C_RED, "$[server]: could not find you, have you joined a channel?\n"));

}