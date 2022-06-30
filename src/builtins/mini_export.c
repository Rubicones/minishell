/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:55 by ejafer            #+#    #+#             */
/*   Updated: 2022/04/25 16:10:36 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"
#include "get_envvars.h"

char **add_var(char **env, int len, char *arg)
{
	int i;
	int j;
	char **new_env;

	(void)j;
	(void)arg;
	new_env = malloc(sizeof(char *) * (len + 1));
	i = -1;
	while (env[++i])
		new_env[i] = ft_strdup(env[i]);
	new_env[i] = ft_strdup(arg);
	return (new_env);
}

char	**mini_export(t_command *cmd, char **env)
{
	char 	**new_env;
	int 	env_len;

	env_len = 0;
	if (!(cmd->argv[1]))
	{
		g_status = 1;
		return (env);
	}
	if (!(ft_strchr(cmd->argv[1], '=')))
	{
		g_status = 0;
		return (env);
	}
	if (!(ft_isalpha(cmd->argv[1][0])))
	{
		g_status = 1;
		return (env);
	}
	while (env[env_len])
		env_len++;
	new_env = add_var(env, env_len, cmd->argv[1]);
	free_env(env);
	g_status = 0;
	return (new_env);
}
