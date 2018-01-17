#include <client.h>

/*
** return the IPv4 address of a DNS
*/

char                *ft_resolve_host(char *argv)
{
    struct hostent  *hptr;
    char            *ip_addr;
    
    /*
    ** dynamically allocate memory for the IP addr
    ** The size can handle either 32-bit IPv4 or 128-bit IPv6
    */

    if (!(ip_addr = (char *)malloc(INET_ADDRSTRLEN)))
        return (NULL);

    /*
    ** gethostbyname failed if return is NULL
    */

    if (!(hptr = gethostbyname(argv)))
        ft_fatal_error("unable to resolve host name");

    /*
    ** check host address type is AF_INET (internet)
    */

    if (hptr->h_addrtype == AF_INET)
    {

        /*
        ** hostent h_addr_list contains a list of IPv4 addresses
        ** that belong to the hostname, I only want 1
        */

        if (*(hptr->h_addr_list))
        {

            /*
            ** In an effort to create a protocol independant resolver
            ** i will use inet_ntop to get the representational value of
            ** the IP addressm be it IPv4 or IPv6
            */

            if (inet_ntop(hptr->h_addrtype, *(hptr->h_addr_list), ip_addr, INET_ADDRSTRLEN))
                return (ip_addr);

        }

    }

    /*
    ** unable to find address, quit
    */

    return (NULL);

}