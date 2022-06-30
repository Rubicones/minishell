/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_bins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:02:47 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/30 17:45:05 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

void	init_command(t_mini *mini, t_token	*current, int pin, int pout)
{
	t_command	*cmd;

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
	if (is_builtin(cmd->name))
	{
		close_fds(cmd);
		exit (0);
	}
	execute_command(mini, cmd);
}

void	init_fork(t_mini *mini, t_token	*current, int pin, int pout)
{
	int			pid;

	pid = fork();
	if (pid > 0)
	{
		close_pipe(pin, pout);
		return ;
	}
	else if (pid < 0)
	{
		close_pipe(pin, pout);
		perror("fork");
		return ;
	}
	else 
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		init_command(mini, current, pin, pout);
	}
}

void	wait_childprocesses(void)
{
	int	exitinfo;

	while (waitpid(-1, &exitinfo, 0) > 0)
		;
	g_status = WEXITSTATUS(exitinfo);
}

void	execute_bins(t_mini *mini)
{
	t_executer_utils	*utils;
	int					fd[2];

	utils = malloc(sizeof(t_executer_utils) * 1);
	fill_executor_struct(utils, mini);
	while (utils->current_fast)
	{
		if (utils->current_fast->type == Pipe)
		{
			if (pipe(fd))
				perror("pipe");
			utils->pout = fd[1];
			init_fork(mini, utils->current_slow, utils->pin, utils->pout);
			utils->pin = fd[0];
			utils->current_slow = utils->current_fast->next;
		}
		utils->current_fast = utils->current_fast->next;
	}
	init_fork(mini, utils->current_slow, utils->pin, utils->pout);
	wait_childprocesses();
}
