/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** Fatal error, end program
*/

void    ft_fatal_error(char *msg)
{

	/*
	** colorful error message lol
	*/

    printf("server: %s%s%s\n", C_RED, msg, C_RST);

    /*
    ** exit with failed status code
    */

    exit(EXIT_FAILURE);

}