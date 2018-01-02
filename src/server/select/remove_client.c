/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_client.c                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <server.h>

/*
** Remove client from array and set
*/

void		ft_remove_client(t_env *env, int sockfd, int index)
{

	/*
	** client connection closed info
	*/

	printf("client with fd [%d] closed\n", sockfd);

	/*
	** close sockfd
	*/

	ft_close(sockfd);

	/*
	** Remove fd from both select sets
	*/

	FD_CLR(sockfd, &env->wset);
	FD_CLR(sockfd, &env->rset);

	/*
	** open space in array
	*/

	env->client[index] = -1;

	/*
	** remove from user/channels list
	*/

	ft_remove_user(env, index);

	/*
	** temp
	*/

	t_user *user = env->users;
	int num = 0;
	while (user)
	{
		num++;
		user = user->next;
	}
	printf("> [ %d ] user(s) online\n", num);

}