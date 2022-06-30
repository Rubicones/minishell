/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:53 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/30 22:07:53 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"
#include "get_envvars.h"

char	**change_pwds(t_command *cmd, char **env, int i)
{
	char	pwd[10000];

	if (i == 1)
	{
		cmd->argv[1] = "OLDPWD";
		env = mini_unset(cmd->argv, env);
		if (!getcwd(pwd, sizeof(pwd)))
			perror(pwd);
		cmd->argv[1] = ft_strjoin("OLDPWD=", pwd);
		env = mini_export(cmd->argv, env);
	}
	if (i == 2)
	{
		cmd->argv[1] = "PWD";
		env = mini_unset(cmd->argv, env);
		if (!getcwd(pwd, sizeof(pwd)))
			perror(pwd);
		cmd->argv[1] = ft_strjoin("PWD=", pwd);
		env = mini_export(cmd->argv, env);
	}
	return (env);
}

char	**mini_cd(t_command *cmd, char **env)
{
	char	*target;

	target = NULL;
	if (cmd->argv[1])
		target = ft_strdup(cmd->argv[1]);
	else
		target = envvar_get("HOME", env);
	env = change_pwds(cmd, env, 1);
	if (chdir(target) == -1)
	{
		perror(target);
		free(target);
		g_status = 1;
		return (env);
	}
	env = change_pwds(cmd, env, 2);
	free(target);
	g_status = 0;
	return (env);
}
