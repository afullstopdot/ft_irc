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

void ringBufS_put (ringBufS *_this, const unsigned char c)
{
    if (_this->count < BUFFSIZE)
    {
      _this->buf[_this->head] = c;
      _this->head = modulo_inc (_this->head, BUFFSIZE);
      ++_this->count;
    }
}