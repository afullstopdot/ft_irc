/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** Handle commands
*/

char		*ft_handle_command(t_env *env, char *buf, int c_index)
{

	char	**argv;

	/*
	** break recieved buffer to check if valid command > execute
	*/

	if ((argv = ft_strsplit(buf, ' ')))
	{

		/*
		** Set username
		*/

		if (ft_strequ(ft_strtrim(argv[0]), "/nick") && argv[1])
			return (ft_set_username(env, argv, c_index));
		else if (ft_strequ(ft_strtrim(argv[0]), "/whoami"))
			return (ft_get_username(env, c_index));
		else if (ft_strequ(ft_strtrim(argv[0]), "/join") && argv[1])
			return (ft_channel_join(env, argv, c_index));
		else if (ft_strequ(ft_strtrim(argv[0]), "/who"))
			return (ft_channel_list(env, c_index));
		else
			return (ft_invalid_command());

	}

	return (ft_invalid_command());

}