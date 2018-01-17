/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:19:32 by amarquez          #+#    #+#             */
/*   Updated: 2018/01/10 15:19:55 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <server.h>

/*
** Initialize the circular buffer queue
** The following clears:
** 		buf, head, tail, count
** and sets head = tail
*/

void	ft_cbuf_init(t_cbuf *buf)
{

	/*
	** Initialize
	*/

	ft_memset(buf, 0, sizeof (*buf));

	/*
	** Clear str
	*/

	ft_strclr(buf->buf);

}