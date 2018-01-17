/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:44:46 by amarquez          #+#    #+#             */
/*   Updated: 2018/01/10 15:44:52 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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