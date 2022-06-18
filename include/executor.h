/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:44:23 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/18 12:10:21 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "minishell.h"

typedef struct s_command
{
	char	*name;
	char	**argv;
	int		*fdin;
	int		*fdout;
}	t_command;

t_command	*new_command(char *name, char **argv, int pin, int pout);
char		*find_path(t_mini *mini, char *name);

void		duplicate_fdout(int *fdout);
void		duplicate_fdin(int *fdin);
void		close_fds(t_command *cmd);

int			*arrint_new(int len);
int			arrint_len(int *arr);
int			*arrint_addback(int *old_arr, int new_elem);
int			builtins_check(t_command *cmd);

void		exec_builtin(t_mini *mini, t_command *cmd, char **argv);

void		open_redir(t_token	*current, t_command *cmd);
void		open_heredoc(char *filename, t_command *cmd);
void		open_redirin(char *filename, t_command *cmd);
void		open_redirout(char *filename, t_command *cmd);
void		open_redirout_a(char *filename, t_command *cmd);

void		mini_echo(t_command *cmd, char **argv);
void		mini_cd(t_command *cmd, char **argv);
char		*mini_pwd(void);

#endif