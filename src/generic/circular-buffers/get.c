#include <server.h>

/*
** Get a byte from the queue
** Return of integer to indicate if an attempt was made t retrieve and empty queue
*/

int     ft_cbuf_get(t_cbuf *buf)
{
    int c;

    if (buf->count > 0)
    {

		c = buf->buf[buf->tail];
		buf->tail = ft_modulo_inc(buf->tail, BUFFSIZE);
		--buf->count;

    }
    else
		c = -1;

    return (c);

}