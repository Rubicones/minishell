/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:23:41 by dgizzard          #+#    #+#             */
/*   Updated: 2022/06/18 13:21:13 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

void	exec_builtin(t_mini *mini, t_command *cmd, char **argv)
{
	if (ft_strncmp(cmd->name, "echo", ft_strlen("echo")) == 0)
		mini_echo(cmd, argv);
	if (ft_strncmp(cmd->name, "cd", ft_strlen("cd")) == 0)
		mini_cd(cmd, argv);
	if (ft_strncmp(cmd->name, "env", ft_strlen("env")) == 0)
		mini_env(mini);
	if (ft_strncmp(cmd->name, "pwd", ft_strlen("pwd")) == 0)
		mini_pwd();
	if (ft_strncmp(cmd->name, "exit", ft_strlen("exit")) == 0)
		mini_exit(mini);
}

int	builtins_check(t_command *cmd)
{
	char	*builtins[] = {"echo","cd", "pwd", "export", "unset", \
	"env", "exit"};
	int		i;

	i = 0;
	while (i < 7)
	{
		if (ft_strncmp(cmd->name, builtins[i], ft_strlen(cmd->name)) == 0)
			return (1);
		i++;
	}
	return (0);
}
