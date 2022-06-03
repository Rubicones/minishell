/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:35:09 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/03 21:41:15 by ejafer           ###   ########.fr       */
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
		parse_to_cmds(mini);
		execute_cmds(mini);
		free(mini->line);
		mini->line = NULL;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_mini *mini;

	mini = malloc(sizeof(t_mini));
	mini->env = env;
	mini->argc = argc;
	mini->argv = argv;
	minishell(mini);
	return (0);
}