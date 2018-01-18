# include <server.h>

/*
** Flush a circular buffer (set everything to default)
*/

void	ft_cbuf_flush(t_cbuf *buf, const int clearBuffer)
{

	/*
	** Defaults
	*/

	buf->count = 0;
	buf->head = 0;
	buf->tail = 0;
	buf->done = 0;

	/*
	** Clear the buffer aswell?
	*/

	if (clearBuffer)
		ft_memset (buf->buf, 0, sizeof (buf->buf));

}
