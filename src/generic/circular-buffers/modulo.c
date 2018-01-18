#include <server.h>


unsigned int 		ft_modulo_inc (const unsigned int value, const unsigned int modulus)
{

    unsigned int 	my_value;

	my_value = value + 1;
    if (my_value >= modulus)
		my_value  = 0;

	return (my_value);

}

unsigned int 		ft_modulo_dec (const unsigned int value, const unsigned int modulus)
{

    unsigned int 	my_value;

	my_value = (0 == value) ? (modulus - 1) : (value - 1);

    return (my_value);

}