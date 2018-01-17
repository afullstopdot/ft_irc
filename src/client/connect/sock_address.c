# include <client.h>

/*
** Fill socket address
*/

void					ft_set_sockaddr(struct sockaddr *sa, int family, int port, in_addr_t address)
{
	struct sockaddr_in	*servaddr;

	/*
	** Set servaddr {}
	*/

	if ((servaddr = (struct sockaddr_in*)sa))
	{

		/*
		** Clear
		*/

		ft_bzero(servaddr, sizeof(servaddr));

		/*
		** Family
		*/

		servaddr->sin_family = family;

		/*
		** Port #
		*/

		servaddr->sin_port = htons(port);

		/*
		** Address
		*/

		servaddr->sin_addr.s_addr = address;
	
	}
	else
		ft_fatal_error("ft_fill_address fail");

}