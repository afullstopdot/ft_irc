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

	/*
	** Set if finished
	*/

	buf->done = FALSE;

}