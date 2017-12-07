/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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