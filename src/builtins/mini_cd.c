/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:53 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/30 12:01:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"
#include "get_envvars.h"

void	change_pwds(char *oldpwd, char *pwd, char **env)
{
	char	*temp;
	int		pos;
	char	*target;

	target = envvar_get("PWD", env);
	pos = envar_position("PWD", env);
	free(env[pos]);
	if (target)
	{
		temp = ft_strjoin("PWD=", pwd);
		env[pos] = ft_strdup(temp);
		free(temp);
	}
	else
		return ;
	free(target);
	target = envvar_get("OLDPWD", env);
	pos = envar_position("OLDPWD", env);
	free(env[pos]);
	if (target)
	{
		temp = ft_strjoin("OLDPWD=", oldpwd);
		env[pos] = ft_strdup(temp);
		free(temp);
	}
	free(target);
}

void	mini_cd(t_command *cmd, char **env)
{
	char	*target;
	char	oldpwd[10000];
	char	pwd[10000];

	target = NULL;
	if (cmd->argv[1])
		target = ft_strdup(cmd->argv[1]);
	else
		target = envvar_get("HOME", env);
	getcwd(oldpwd, sizeof(oldpwd));
	if (chdir(target) == -1)
	{
		perror(target);
		free(target);
		g_status = 1;
		return ;
	}
	getcwd(pwd, sizeof(pwd));
	change_pwds(oldpwd, pwd, env);
	free(target);
	g_status = 0;
}
