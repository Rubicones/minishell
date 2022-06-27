/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:54:05 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/27 14:57:38 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sighandler_interupt(int signo)
{
	if (signo == SIGINT)
	{
		g_status = 128 + SIGINT;
		if (write(2, "\n", 1) < 0)
			perror("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	sighandler_exit(int signo)
{
	if (signo == SIGUSR2)
	{
		while (waitpid(-1, &g_status, 0) > 0)
		{
		}
		exit(g_status);
	}
}

void	init_sighandler(void)
{
	rl_catch_signals = 1;
	signal(SIGINT, sighandler_interupt);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGUSR2, sighandler_exit);
}
