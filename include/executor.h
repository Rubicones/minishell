/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:20:28 by ejafer            #+#    #+#             */
/*   Updated: 2022/07/01 01:05:32 by ejafer           ###   ########.fr       */
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

typedef struct s_executer_utils
{
	int		pin;
	int		pout;
	t_token	*current_fast;
	t_token	*current_slow;
}	t_executer_utils;

void		execute_bins(t_mini *mini);
t_command	*new_command(char *name, char **argv, int pin, int pout);
char		*find_path(t_mini *mini, char *name);

void		fill_executor_struct(t_executer_utils *utils, t_mini *mini);

void		duplicate_fdout(int *fdout);
void		duplicate_fdin(int *fdin);
void		close_fds(t_command *cmd);
void		close_pipe(int pin, int pout);

int			*arrint_new(int len);
int			arrint_len(int *arr);
int			*arrint_addback(int *old_arr, int new_elem);
int			is_builtin(char	*name);

void		execute_builtin(t_mini *mini, t_command *cmd);
void		execute_command(t_mini *mini, t_command *cmd);
void		post_execution(t_mini *mini);

void		open_redir(t_token	*current, t_command *cmd);
void		open_heredoc(char *filename, t_command *cmd);
void		open_redirin(char *filename, t_command *cmd);
void		open_redirout(char *filename, t_command *cmd);
void		open_redirout_a(char *filename, t_command *cmd);

void		mini_echo(t_command *cmd);
void		mini_exit(t_command *cmd);
char		*mini_env(t_mini *mini);
char		**mini_cd(char **argv, char **env);
char		*mini_pwd(void);
char		**mini_unset(char **argv, char **env);
char		**unset_var(char *var, char **env);
char		**export_var(char *arg, char **env);
char		**mini_export(char **argv, char **env);
void		free_env(char **env);

char		**real_cd(char *target, char **env);
char		**cd_to_many_arguments(char **env);
char		**cd_no_arguments(char **env);
char		**cd_back(char **env);

#endif