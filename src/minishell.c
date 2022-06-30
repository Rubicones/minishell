/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:35:09 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/30 19:24:12 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	minishell(t_mini *mini)
{
	while (1)
	{
		mini->line = readline(SHELLNAME);
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

t_mini	*init_mini(int argc, char **argv, char **env)
{
	int		i;
	t_mini	*tmp;

	tmp = malloc(sizeof(t_mini));
	tmp->pid = getpid();
	tmp->heredocid = 0;
	tmp->env = ft_arrnew(ft_arrlen(env));
	i = -1;
	while (env[++i])
		tmp->env[i] = ft_strdup(env[i]);
	tmp->argc = argc;
	tmp->argv = argv;
	return (tmp);
}

char	**dup_env(char **env)
{
	int		i;
	char	**new_env;

	i = 0;
	while (env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (env[++i])
		new_env[i] = ft_strdup(env[i]);
	return (new_env);
}

int	main(int argc, char **argv, char **env)
{
	t_mini	*mini;
	char	**new_env;

	g_status = 0;
	init_sighandler();
	mini = init_mini(argc, argv, env);
	minishell(mini);
	return (0);
}
