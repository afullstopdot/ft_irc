/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:31:11 by amarquez          #+#    #+#             */
/*   Updated: 2018/01/10 15:31:12 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

/*
** Put a byte to the queue, incoming byte is dropped if the queue is full
*/

void	ft_cbuf_put(t_cbuf *buf, const char c)
{

    if (buf->count < BUFFSIZE)
    {

		buf->buf[buf->head] = c;
		buf->head = ft_modulo_inc(buf->head, BUFFSIZE);
		++buf->count;

    }

}