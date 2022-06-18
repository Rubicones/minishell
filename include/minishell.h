/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:44:32 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/17 19:01:45 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <string.h>
# include <signal.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>

# define QUOTES_D	'"'
# define QUOTES_S	'\''
# define SPACE		' '

# define HEREDOC	"<<"
# define REDIRIN	"<"
# define REDIROUT	">"
# define REDIROUT_A ">>"
# define PIPE		"|"

typedef enum e_type
{
	Heredoc,
	Redirin,
	Redirout,
	Redirout_a,
	Pipe,
	Command
}	t_type;

typedef struct s_token
{
	char			*name;
	t_type			type;
	char			**argv;
	struct s_token	*next;
}	t_token;

typedef struct s_mini
{
	int		argc;
	char	**argv;
	char	**env;
	char	*line;
	char	**splited_line;
	t_token	**tokens;
}	t_mini;

typedef struct s_parser
{
	char			**words;
	int				command_is_set;
	int				index;
	t_token			*current_command;
	t_token			**head;
}	t_parser;

void		split_line(t_mini *mini);
void		parse(t_mini *mini);
void		execute(t_mini *mini);
char		*mini_env(t_mini *mini);
void		throw_error(int error_code);

t_token		*new_token(char	*new_name, t_type new_type);
void		token_push_back(t_token **head, t_token *to_push);

t_parser	*new_parser(char **words);
char		*current_word(t_parser *data);
int			is_command_set(t_parser *data);
int			is_pipe(t_parser *data);
int			is_redir(t_parser *data);
int			is_heredoc(char	*word);
int			is_redirin(char	*word);
int			is_redirout(char *word);
int			is_redirout_a(char *word);
void		set_redir(t_parser *data);
void		set_pipe(t_parser *data);
void		set_command(t_parser *data);

#endif