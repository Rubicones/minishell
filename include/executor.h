/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:44:23 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/14 13:16:45 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_command
{
	char	*name;
	char	**argv;
	int		*fdin;
	int		*fdout;
}	t_command;

t_command	*new_command(char *name, char **argv);
void		close_fds(t_command *cmd);

int			*arrint_new(int len);
int			arrint_len(int *arr);
int			*arrint_addback(int *old_arr, int new_elem);

void		open_heredoc(char *filename, t_command *cmd);
void		open_redirin(char *filename, t_command *cmd);
void		open_redirout(char *filename, t_command *cmd);
void		open_redirout_a(char *filename, t_command *cmd);

#endif