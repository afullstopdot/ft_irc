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

void ringBufS_init (ringBufS *_this)
{

	ft_memset (_this, 0, sizeof (*_this));

}