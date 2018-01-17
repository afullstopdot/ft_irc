/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <client.h>

int				main(int argc, char **argv)
{

	/*
	** client environment
	*/

	t_cli		env;

	/*
	** User input
	*/

	char		*cmd;

	/*
	** Check if the user is trying to connect on client startup
	*/

	if (argc == 3)
		ft_connect_to_server(&env, argv);

	/*
	** Read from stdin
	*/

	while ((cmd = ft_wreadline(0)))
	{
		
		/*
		** check that command is not empty
		*/

		if (ft_strlen(cmd))
		{
			
			/*
			** Handle
			*/

						

		}
		else
			ft_strdel(&cmd);

		/*
		** Display prompt (username)
		*/

		

	}

	/*
	** End
	*/

    return (EXIT_SUCCESS);
}