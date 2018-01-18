# include <server.h>

/*
** error msg
*/

char		*ft_uerror(char *msg)
{

	char	*resp;

	/*
	** build message
	*/

	if ((resp = ft_strjoin(C_RED, msg)))
	{

		/*
		** reset color
		*/

		return (ft_strjoin(resp, C_RST));

	}

	return (ft_strdup(msg));

}

/*
** success msg
*/

char		*ft_usuccess(char *msg)
{

	char	*resp;

	/*
	** build message
	*/

	if ((resp = ft_strjoin(C_GRN, msg)))
	{

		/*
		** reset color
		*/

		return (ft_strjoin(resp, C_RST));

	}

	return (ft_strdup(msg));

}