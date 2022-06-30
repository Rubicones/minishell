/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 02:58:27 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/29 15:44:53 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

void	execute_builtin(t_mini *mini, t_command *cmd)
{
	if (ft_strncmp(cmd->name, "echo", ft_strlen("echo")) == 0)
		mini_echo(cmd);
	if (ft_strncmp(cmd->name, "cd", ft_strlen("cd")) == 0)
		mini_cd(cmd, mini->env);
	if (ft_strncmp(cmd->name, "env", ft_strlen("env")) == 0)
		mini_env(mini);
	if (ft_strncmp(cmd->name, "pwd", ft_strlen("pwd")) == 0)
		mini_pwd();
	if (ft_strncmp(cmd->name, "exit", ft_strlen("exit")) == 0)
		mini_exit(cmd);
	if (ft_strncmp(cmd->name, "unset", ft_strlen("unset")) == 0)
		mini->env = mini_unset(cmd, mini->env);
	if (ft_strncmp(cmd->name, "export", ft_strlen("export")) == 0)
		mini->env = mini_export(cmd, mini->env);
}
