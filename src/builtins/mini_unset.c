/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:59 by ejafer            #+#    #+#             */
/*   Updated: 2022/04/25 16:10:38 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"
#include "get_envvars.h"

char **delete_var(char **env, int pos, int len)
{
	int i;
	char **new_env;

	new_env = malloc(sizeof(char *) * len + 1);
	i = 0;
	while (i < pos)
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	while (env[i + 1])
	{
		new_env[i] = env[i + 1];
		i++;
	}
	return (new_env);
}

void free_env(char **env)
{
	int i;

	i = -1;
	while (env[++i])
		free(env[i]);
	free(env);
}
//надо освобождать env, но тогда по какой-то причине в new_env будет мусор, хотя там копия,
// а не указатель, надо разбираться
char	**mini_unset(t_command *cmd, char **env)
{
	int 	i;
	char 	**new_env;
	int 	env_len;

	env_len = 0;
	i = envar_position(cmd->argv[1], env);
	if (!(envvar_get(cmd->argv[1], env)))
	{
		g_status = 1;
		return (env);
	}
	while (env[env_len])
		env_len++;
	new_env = delete_var(env, i, env_len);
	free_env(env);
	g_status = 0;
	return (new_env);
}
