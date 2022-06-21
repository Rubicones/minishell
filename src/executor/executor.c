/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:02:47 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/21 14:15:45 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

void	execute_command(t_mini *mini, t_command *cmd)
{
	char	*path;

	if (is_builtin(cmd))
		execute_builtin(mini, cmd);
	else
	{
		path = find_path(mini, cmd->name);
		if (path)
			execute_bin(mini, cmd, path);
		else
			perror(cmd->name);
	}
}

void	close_pipe(int pin, int pout)
{
	if (pin != -1)
		close(pin);
	if (pout != -1)
		close(pout);
}

void	init_command(t_mini *mini, t_token	*current, int pin, int pout)
{
	int			pid;
	t_command	*cmd;

	pid = fork();
	if (pid != 0)
	{
		close_pipe(pin, pout);
		return ;
	}
	signal(SIGINT, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	cmd = new_command(NULL, NULL, pin, pout);
	while (current && current->type != Pipe)
	{
		if (current->type == Command)
		{
			cmd->name = current->name;
			cmd->argv = current->argv;
		}
		else
			open_redir(current, cmd);
		current = current->next;
	}
	execute_command(mini, cmd);
}

void	wait_childprocesses(void)
{
	while (waitpid(-1, NULL, 0) > 0)
	{
	}
}

void	execute(t_mini *mini)
{
	int			pin;
	int			pout;
	int			fd[2];
	t_token		*current_fast;
	t_token		*current_slow;

	pin = -1;
	pout = -1;
	current_fast = *mini->tokens;
	current_slow = *mini->tokens;
	while (current_fast)
	{
		if (current_fast->type == Pipe)
		{
			if (pipe(fd))
				perror(NULL);
			pout = fd[1];
			init_command(mini, current_slow, pin, pout);
			pin = fd[0];
			current_slow = current_fast->next;
		}
		current_fast = current_fast->next;
	}
	init_command(mini, current_slow, pin, pout);
	wait_childprocesses();
	post_execution(mini);
}
