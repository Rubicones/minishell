/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:53 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/30 15:53:23 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"
#include "get_envvars.h"

char	**change_pwds(t_command *cmd, char **env, char *whatpwd)
{
	char	pwd[10000];

	cmd->argv[1] = whatpwd;
	env = mini_unset(cmd->argv, env);
	if (!getcwd(pwd, sizeof(pwd)))
		perror(pwd);
	cmd->argv[1] = ft_strjoin(ft_strjoin(whatpwd, "="), pwd);
	env = mini_export(cmd->argv, env);
	return (env);
}

char	**real_cd(t_command *cmd, char **env, char *target)
{
	env = change_pwds(cmd, env, "OLDPWD");
	if (chdir(target) == -1)
	{
		perror(target);
		free(target);
		g_status = 1;
		return (env);
	}
	env = change_pwds(cmd, env, "PWD");
	free(target);
	g_status = 0;
	return (env);
}

char	**mini_cd(t_command *cmd, char **env)
{
	char	*target;

	if (!(cmd->argv[1]))
	{
		target = envvar_get("HOME", env);
		cmd->argv[1] = NULL;
		cmd->argv[2] = NULL;
		env = real_cd(cmd, env, target);
		return (env);
	}
	else if (cmd->argv[1] && !(cmd->argv[2]))
	{
		target = ft_strdup(cmd->argv[1]);
		return (real_cd(cmd, env, target));
	}
	else
		g_status = 1;
	return (env);
}
