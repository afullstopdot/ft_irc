/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:22:31 by amarquez          #+#    #+#             */
/*   Updated: 2018/01/10 15:22:32 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <server.h>

/*
** Determine whether or not the circular buffer queue is empty
*/

int ft_cbuf_empty(t_cbuf *buf)
{

	return (0 == buf->count);

}

/*
** Determine whether or not the circular buffer queue is full
*/

int ft_cbuf_full(t_cbuf *buf)
{

    return (buf->count >= BUFFSIZE);

}