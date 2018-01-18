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