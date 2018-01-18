# include <server.h>

/*
** Handle commands
*/

char		*ft_resp(char *start, char *msg)
{


	char	*resp;

	if ((resp = ft_strjoin(start, ft_strjoin(msg, C_RST))))
	{

		/*
		** reset color
		*/

		return (resp);

	}

	return (ft_strdup(msg));

}