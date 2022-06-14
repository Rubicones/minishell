/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:35:09 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/14 14:07:20 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ТЕСТОВАЯ ФУНКЦИЯ
void	execute_cmds(t_mini *mini)
{
	int		i;
	t_token	*current;

	current = *mini->tokens;
	while (current)
	{
		printf("Token: %s; type: %d; argv: ", current->name, current->type);
		i = -1;
		while (current->argv[++i])
			printf("%s ", current->argv[i]);
		printf("\n");
		current = current->next;
	}
	*mini->tokens = NULL;
}

// ТЕСТОВАЯ ФУНКЦИЯ
void	show_splited_line(t_mini *mini)
{
	int	i;

	printf("Splited line:\n");
	i = -1;
	while (mini->splited_line[++i])
		printf("%s\n", mini->splited_line[i]);
	printf("\n");
}

void	minishell(t_mini *mini)
{
	while (1)
	{
		mini->line = readline("\033[32mMinishell\033[0m$: ");
		add_history(mini->line);
		split_line(mini);
		parse(mini);
		execute(mini);
		free(mini->line);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_mini	*mini;

	mini = malloc(sizeof(t_mini));
	mini->env = env;
	mini->argc = argc;
	mini->argv = argv;
	minishell(mini);
	return (0);
}
