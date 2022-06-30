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
	char **new_env;

	new_env = malloc(sizeof(char *) * (len + 1));
	i = -1;
	while (env[++i])
		new_env[i] = ft_strdup(env[i]);
	new_env[i] = ft_strdup(arg);
	return (new_env);
}

int isvalid_arg(char *arg)
{
	if (!(ft_isalpha(arg[0])))
	{
		g_status = 1;
		return (1);
	}
	if (!(ft_strchr(arg, '=')) || getcwd(arg, sizeof(arg)))
	{
		g_status = 0;
		return (0);
	}
	g_status = 0;
	return (2);

}

char	**export_var(char *arg, char **env)
{
	char 	**new_env;
	int 	env_len;

	env_len = 0;
	if (!arg)
	{
		g_status = 1;
		return (env);
	}
	while (env[env_len])
		env_len++;
//	if (isvalid_arg(arg) == 2)
//		new_env = add_var(env, env_len, arg);
//	else if (isvalid_arg(arg) == 0 || isvalid_arg(arg) == 1)
//		return (env);
	new_env = add_var(env, env_len, arg);

	free_env(env);
	return (new_env);
}

char	**mini_export(t_command *cmd, char **env)
{
	int		i;

	i = 0;
	while (cmd->argv[++i])
		env = export_var(cmd->argv[i], env);
	return (env);
}
