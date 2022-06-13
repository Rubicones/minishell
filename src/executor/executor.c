/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:02:47 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/13 18:26:34 by                  ###   ########.fr       *//
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/libft.h"

char *find_path(t_mini *mini, t_cmd *cmd)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(mini->env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(mini->env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd->name);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void child_process(t_cmd *cmds, t_mini *mini)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit();
	pid = fork();
	if (pid == -1)
		exit();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		path = find_path(mini, cmd);
		if (execve(path, cmds->name, mini->env) == -1)
			exit();
	}
}

void parent_process(t_cmd *cmds)
{
	dup2(cmds->cin, STDIN_FILENO);
	while (cmds->next)
	{

	}

}


int	executor(t_mini *mini)
{

}
