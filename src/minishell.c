/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:35:09 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/21 02:40:04 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(t_mini *mini)
{
	while (1)
	{
		mini->line = readline("\033[32mMinishell\033[0m$: ");
		add_history(mini->line);
		split_line(mini);
		parse(mini);
		execute(mini);
	}
}

void	sighandler_exit(int n)
{
	signal(SIGQUIT, SIG_IGN);
	kill(0, SIGQUIT);
	signal(SIGQUIT, SIG_DFL);
	while (waitpid(-1, NULL, 0) > 0)
	{
	}
	exit(0);
}

int	main(int argc, char **argv, char **env)
{
	t_mini	*mini;

	signal(SIGINT, SIG_IGN);
	signal(SIGUSR2, sighandler_exit);
	//signal(SIGTSTP, signal_handler);
	mini = malloc(sizeof(t_mini));
	mini->pid = getpid();
	printf("pid: %d\n", mini->pid);
	mini->heredocid = 0;
	mini->env = env;
	mini->argc = argc;
	mini->argv = argv;
	minishell(mini);
	return (0);
}
