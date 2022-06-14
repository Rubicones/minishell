/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:02:47 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/14 14:03:16 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

char	*find_path(t_mini *mini, char *name)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(mini->env[i], "PATH=", 5))
		i++;
	paths = ft_split(mini->env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, name);
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
	return (NULL);
}

void	dup_fdouts(int *fdout)
{
	int	i;

	i = -1;
	while (fdout[++i] != -1)
	{
		dup2(fdout[i], STDOUT_FILENO);
		close(fdout[i]);
	}
}

void	dup_fdins(int *fdin)
{
	int	i;

	i = -1;
	while (fdin[++i] != -1)
	{
		dup2(fdin[i], STDIN_FILENO);
		close(fdin[i]);
	}
}

void	child_process(t_mini *mini, t_command *cmd)
{
	pid_t	pid;
	char	*path;

	pid = fork();
	if (pid == 0)
	{
		path = find_path(mini, cmd->name);
		if (path == NULL)
			exit(-1);
		dup_fdouts(cmd->fdout);
		dup_fdins(cmd->fdin);
		printf("%s\n", path);
		if (execve(path, cmd->argv, mini->env) == -1)
			exit(-1);
	}
	else if (pid < 0)
	{
		exit(-1);
	}
	else
	{
		close_fds(cmd);
		free(cmd->fdin);
		free(cmd->fdout);
		free(cmd);
	}
}

void	parent_process(t_mini *mini, t_token *token)
{
	int			fd[2];
	int			wpid;
	t_command	*cmd;

	fd[0] = -1;
	fd[1] = -1;
	cmd = NULL;
	while (token)
	{
		if (token->type == Heredoc)
			open_heredoc(token->argv[1], cmd);
		else if (token->type == Redirin)
			open_redirin(token->argv[1], cmd);
		else if (token->type == Redirout)
			open_redirout(token->argv[1], cmd);
		else if (token->type == Redirout_a)
			open_redirout_a(token->argv[1], cmd);
		else if (token->type == Command)
		{
			cmd = new_command(token->name, token->argv);
			if (fd[0] != -1)
				cmd->fdin = arrint_addback(cmd->fdin, fd[0]);
		}
		else if (token->type == Pipe)
		{
			if (pipe(fd) == -1)
				exit(-1);
			if (fd[1] != -1)
				cmd->fdout = arrint_addback(cmd->fdout, fd[1]);
			child_process(mini, cmd);
		}
		token = token->next;
	}
	child_process(mini, cmd);
	while ((wpid = waitpid(-1, NULL, 0)) > 0);
}

void	executor(t_mini *mini)
{
	t_token	*cur_tokens;

	cur_tokens = *mini->tokens;
	parent_process(mini, cur_tokens);
}
