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