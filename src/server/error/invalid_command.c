# include <server.h>

/*
** Fatal error, end program
*/

char		*ft_invalid_command(void)
{

	char	*resp;

	/*
	** build response
	*/

	if ((resp = ft_strjoin(C_RED, "$[server]: invalid command\n")))
	{

		/*
		** reset color then return
		*/

		return (ft_strjoin(resp, C_RST));

	}

    return (ft_strdup("$[server]: invalid command\n"));

}