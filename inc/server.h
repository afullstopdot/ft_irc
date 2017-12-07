/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:11:14 by amarquez          #+#    #+#             */
/*   Updated: 2017/07/11 15:12:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

/*
** header with prototypes, headers and constants used by both server & client
*/

# include <irc.h>

/*
** 2nd argument to listen()
*/

# define LISTENQ 1024

/*
** max text line length
*/

#define	MAXLINE	4096

/*
** buffer size for reads and writes
*/

#define	BUFFSIZE 8192

#endif