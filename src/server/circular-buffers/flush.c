/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:33:19 by amarquez          #+#    #+#             */
/*   Updated: 2018/01/10 15:33:21 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** Flush a circular buffer (set everything to default)
*/

void	ft_cbuf_flush(t_cbuf *buf, const int clearBuffer)
{

	/*
	** Defaults
	*/

	buf->count = 0;
	buf->head = 0;
	buf->tail = 0;

	/*
	** Clear the buffer aswell?
	*/

	if (clearBuffer)
		ft_memset (buf->buf, 0, sizeof (buf->buf));

}
