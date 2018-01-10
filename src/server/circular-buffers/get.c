/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:26:59 by amarquez          #+#    #+#             */
/*   Updated: 2018/01/10 15:27:20 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

/*
** Get a byte from the queue
** Return of integer to indicate if an attempt was made t retrieve and empty queue
*/

int ringBufS_get (ringBufS *_this)
{
    int c;
    if (_this->count>0)
    {
      c           = _this->buf[_this->tail];
      _this->tail = modulo_inc (_this->tail, BUFFSIZE);
      --_this->count;
    }
    else
    {
      c = -1;
    }
    return (c);
}