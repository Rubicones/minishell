/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:35:09 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/29 13:47:57 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	minishell(t_mini *mini)
{
	while (1)
	{
		mini->line = readline("\033[32mMinishell\033[0m$: ");
		if (!mini->line)
		{
			g_status = 128 - 1;
			if (write(2, "\n", 1) < 0)
				perror("\n");
			exit(g_status);
		}
		if (ft_strlen(mini->line) == 0 && mini->line[0] == 0)
			;
		else
		{
			add_history(mini->line);
			resolve_envvars(mini);
			split_line(mini);
			parse(mini);
			execute(mini);
		}
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
