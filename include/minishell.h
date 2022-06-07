/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:44:32 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/07 17:00:18 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <signal.h>
# include <stdlib.h>
# include <fcntl.h>

# define QUOTES_D	'"'
# define QUOTES_S	'\''
# define SPACE		' '

# define HEREDOC	"<<"
# define REDERIN	"<"
# define REDEROUT	">"
# define REDEROUT_A ">>"
# define PIPE		"|"

typedef struct s_cmd
{
	char			*name;
	int				cin;
	int				cout;
	char			**argv;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_mini
{
	int		argc;
	char	**argv;
	char	**env;
	char	*line;
	char	**splited_line;
	void	**cmds;
}	t_mini;

void	split_line(t_mini *mini);
void	parse_to_cmds(t_mini *mini);
void	execute_cmds(t_mini *mini);
char	*mini_env(t_mini *mini);
void	throw_error(int error_code);

#endif