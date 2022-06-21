/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 02:55:32 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/21 02:58:04 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

void	execute_bin(t_mini *mini, t_command *cmd, char *path)
{
	duplicate_fdout(cmd->fdout);
	duplicate_fdin(cmd->fdin);
	if (execve(path, cmd->argv, mini->env) == -1)
		perror(NULL);
	free(path);
}
