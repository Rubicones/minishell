/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:59 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/30 16:06:56 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"
#include "get_envvars.h"

char	**delete_var(char **env, int pos)
{
	int		i;
	char	**new_env;

	new_env = ft_arrnew(ft_arrlen(env) - 1);
	i = -1;
	while (++i < pos)
		new_env[i] = ft_strdup(env[i]);
	while (env[++i])
		new_env[i] = ft_strdup(env[i + 1]);
	return (new_env);
}

void	free_env(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		free(env[i]);
	free(env);
}

char	**mini_unset(t_command *cmd, char **env)
{
	int		i;
	char	**new_env;

	i = envar_position(cmd->argv[1], env);
	if (!env[i])
	{
		g_status = 1;
		return (env);
	}
	new_env = delete_var(env, i);
	free_env(env);
	g_status = 0;
	return (new_env);
}
