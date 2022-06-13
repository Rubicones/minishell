/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:02:47 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/13 21:13:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include "../../include/libft.h"

char *find_path(t_mini *mini, char *name)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(mini->env[i], "PATH", 4))
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

void child_process(t_mini *mini, t_command *cmd)
{
	pid_t	pid;
	char	*path;

	pid = fork();
	if (pid == 0)
	{
		path = find_path(mini, cmd->name);
		if (path == NULL)
			exit(-1);
		if (cmd->fdout != 1)
		{
			dup2(cmd->fdout, STDOUT_FILENO);
			close(cmd->fdout);
		}
		if (execve(path, cmd->argv, mini->env) == -1)
			exit(-1);
	}
	else if (pid < 0)
	{
		exit(-1);
	}
	else
	{
		if (cmd->fdout != 1)
			close(cmd->fdout);
	}
}

void heredoc_fun(char **envp, char *filename, t_command *cmd)
{
	return ;
}

void redir_in_fun(char **envp, char *filename, t_command *cmd)
{
	return ;
}

void redir_out_fun(char **envp, char *filename, t_command *cmd)
{
	int fd;

	fd = open(filename, O_TRUNC | O_WRONLY | O_CREAT, 0664);
	if (cmd->fdout != 1)
		close(cmd->fdout);
	cmd->fdout = fd;
	return ;
}

t_command	*new_command(char *new_name)
{
	t_command	*tmp;

	tmp = malloc(sizeof(t_command) * 1);
	tmp->name = new_name;
	tmp->argv = ft_arrnew(1);
	tmp->argv[0] = new_name;
	tmp->fdin = 0;
	tmp->fdout = 1;
	return (tmp);
}

void parent_process(t_mini *mini, t_token *token)
{
	int fd[2];
	int wpid;
	t_command *cmd;

	cmd = new_command(token->name);
	while (token)
	{
		if (token->type == Heredoc)
			heredoc_fun(mini->env, token->argv[1], cmd);
		else if (token->type == Redirin)
			redir_in_fun(mini->env, token->argv[1], cmd);
		else if (token->type == Redirout)
			redir_out_fun(mini->env, token->argv[1], cmd);
		else if (token->type == Command)
		{
			cmd->name = token->name;
			cmd->argv = token->argv;
		}
		else if (token->type == Pipe)
		{
			pipe(fd);
			child_process(mini, cmd);
		}
		token = token->next;
	}
	child_process(mini, cmd);
	while ((wpid = waitpid(-1, NULL, 0)) > 0);
}


int	executor(t_mini *mini)
{
	t_token *cur_tokens;

	cur_tokens = *mini->tokens;
	parent_process(mini, cur_tokens);
}
