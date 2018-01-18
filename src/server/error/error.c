# include <server.h>

/*
** Fatal error, end program
*/

void    ft_fatal_error(char *msg)
{

	/*
	** colorful error message lol
	*/

    printf("irc: %s%s%s\n", C_RED, msg, C_RST);

    /*
    ** exit with failed status code
    */

    exit(EXIT_FAILURE);

}