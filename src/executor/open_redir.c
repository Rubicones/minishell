/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:55:17 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/17 19:07:25 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	open_heredoc(char *filename, t_command *cmd)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(filename);
		exit(0);
	}
	cmd->fdin = arrint_addback(cmd->fdin, fd);
}

void	open_redirin(char *filename, t_command *cmd)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(filename);
		exit(0);
	}
	cmd->fdin = arrint_addback(cmd->fdin, fd);
}

void	open_redirout(char *filename, t_command *cmd)
{
	int	fd;

	fd = open(filename, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(filename);
		exit(0);
	}
	cmd->fdout = arrint_addback(cmd->fdout, fd);
}

void	open_redirout_a(char *filename, t_command *cmd)
{
	int	fd;

	fd = open(filename, O_APPEND | O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(filename);
		exit(0);
	}
	cmd->fdout = arrint_addback(cmd->fdout, fd);
}
