/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** Send message (temporary)
** env - server environment
** argv - message the user is trying to send to someone [/msg <nickname> "hi" "there"]
** c_index - the index of the user in the env->client array
** format - [msg from <nickname>]: Hi There
*/

char		*ft_send_message(t_env **env, char **argv, int c_index)
{

	(void)argv;
	printf("index - %d\n", c_index);
	ft_putendl((*env)->users[c_index].nick);

	/*
	** Find our user
	*/

	return ft_resp(C_RED, "$[server]: could not find you!\n");

}