/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:35:09 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/21 15:30:37 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(t_mini *mini)
{
	while (1)
	{
		mini->line = readline("\033[32mMinishell\033[0m$: ");
		if (!mini->line)
			break ;
		add_history(mini->line);
		split_line(mini);
		parse(mini);
		execute(mini);
	}
}

void	sighandler_stop(int signo)
{
	if (signo == SIGTSTP)
	{
		exit(128 + SIGTSTP);
	}
}

void	sighandler_interupt(int signo)
{
	if (signo == SIGINT)
	{
		rl_point = 0;
		rl_mark = 0;
		rl_end = 0;
		rl_line_buffer[0] = 0;
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}

void	sighandler_exit(int signo)
{
	if (signo == SIGUSR2)
	{
		signal(SIGQUIT, SIG_IGN);
		kill(0, SIGQUIT);
		signal(SIGQUIT, SIG_DFL);
		while (waitpid(-1, NULL, 0) > 0)
		{
		}
		exit(0);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_mini	*mini;

	rl_catch_signals = 1;
	signal(SIGINT, sighandler_interupt);
	signal(SIGTSTP, sighandler_stop);
	signal(SIGUSR2, sighandler_exit);
	mini = malloc(sizeof(t_mini));
	mini->pid = getpid();
	mini->heredocid = 0;
	mini->env = env;
	mini->argc = argc;
	mini->argv = argv;
	minishell(mini);
	return (0);
}
