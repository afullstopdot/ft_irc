/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <irc.h>

/*
** dump the correct usage
*/

void    ft_dump_usage(void)
{

	/*
	** Dump the program usage
	*/

    printf("usage: ./ft_irc\n");

    /*
    ** Exit
    */

	exit(EXIT_SUCCESS);
}