/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:54:05 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/29 16:02:35 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sighandler_quit(int signo)
{
	if (signo == SIGQUIT)
		g_status = 128 + SIGQUIT;
}

void	sighandler_interupt(int signo)
{
	if (signo == SIGINT)
	{
		g_status = 128 + SIGINT;
		if (write(2, "\n", 1) < 0)
			perror("\n");
		rl_on_new_line();
		rl_point = 0;
		rl_end = 0;
		rl_line_buffer[0] = 0;
		rl_redisplay();
	}
}

void	init_sighandler(void)
{
	signal(SIGINT, sighandler_interupt);
	signal(SIGQUIT, sighandler_quit);
}
