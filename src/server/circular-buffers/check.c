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

int ringBufS_empty (ringBufS *_this)
{

	return (0 == _this->count);

}

/*
** Determine whether or not the circular buffer queue is full
*/

int ringBufS_full (ringBufS *_this)
{

    return (_this->count >= BUFFSIZE);

}