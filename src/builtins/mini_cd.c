/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:53 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/30 14:41:09 by ejafer           ###   ########.fr       */
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

	pos = envar_position("PWD", env);
	if (env[pos])
	{
		temp = env[pos];
		env[pos] = ft_strjoin("PWD=", oldpwd);
		free(temp);
	}
	else
		return ;
	pos = envar_position("OLDPWD", env);
	if (env[pos])
	{
		temp = env[pos];
		env[pos] = ft_strjoin("OLDPWD=", oldpwd);
		free(temp);
	}
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
	if (!getcwd(oldpwd, sizeof(oldpwd)))
		perror(oldpwd);
	if (chdir(target) == -1)
	{
		perror(target);
		free(target);
		g_status = 1;
		return ;
	}
	if (!getcwd(pwd, sizeof(pwd)))
		perror(pwd);
	change_pwds(oldpwd, pwd, env);
	free(target);
	g_status = 0;
}
