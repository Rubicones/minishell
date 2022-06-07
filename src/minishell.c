/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:35:09 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/07 18:03:52 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ТЕСТОВАЯ ФУНКЦИЯ
void	execute_cmds(t_mini *mini)
{
	t_cmd	*current;

	current = *mini->cmds;
	while (current)
	{
		printf("command name: %s\n", current->name);
		current = current->next;
	}
	*mini->cmds = NULL;
}

// ТЕСТОВАЯ ФУНКЦИЯ
void	show_splited_line(t_mini *mini)
{
	int	i;

	printf("_____\n");
	i = -1;
	while (mini->splited_line[++i])
		printf("%s\n", mini->splited_line[i]);
}

void	minishell(t_mini *mini)
{
	while (1)
	{
		mini->line = readline("\033[32mMinishell\033[0m$: ");
		add_history(mini->line);
		split_line(mini);
		show_splited_line(mini); //тестовая функция
		//parse_to_cmds(mini);
		//execute_cmds(mini); //тестовая функция
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
