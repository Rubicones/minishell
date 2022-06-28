/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:35:09 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/28 16:15:34 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(t_mini *mini)
{
	while (1)
	{
		mini->line = readline("\033[32mMinishell\033[0m$: ");
		if (!mini->line)
		{
			printf("\n");
			break ;
		}
		add_history(mini->line);
		resolve_envvars(mini);
		split_line(mini);
		parse(mini);
		execute(mini);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_mini	*mini;

	g_status = 0;
	init_sighandler();
	mini = malloc(sizeof(t_mini));
	mini->pid = getpid();
	mini->heredocid = 0;
	mini->env = env;
	mini->argc = argc;
	mini->argv = argv;
	minishell(mini);
	return (0);
}
