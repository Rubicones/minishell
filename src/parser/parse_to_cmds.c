/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:20:31 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/07 15:13:24 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	cmd_pushback(void **head, t_cmd *cmd)
{
	t_cmd	*current;

	current = *head;
	while (current->next)
		current = current->next;
	current->next = cmd;
}

t_cmd	*new_cmd(void **head, char *name)
{
	t_cmd	*tmp;

	tmp = malloc(sizeof(t_cmd) * 1);
	if (*head == NULL)
		*head = tmp;
	else
		cmd_pushback(head, tmp);
	tmp->name = name;
	tmp->argv = ft_arrnew(0);
	tmp->cin = 0;
	tmp->cout = 1;
	tmp->next = NULL;
	return (tmp);
}

void	cmd_change_cin(t_cmd *cmd, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (cmd->cout != 0)
		close(cmd->cout);
	cmd->cin = fd;
}

void	cmd_change_cout(t_cmd *cmd, char *filename)
{
	int	fd;

	fd = open(filename, O_CREAT || O_WRONLY);
	if (cmd->cout != 1)
		close(cmd->cout);
	cmd->cout = fd;
}

void	cmd_change_cout_append(t_cmd *cmd, char *filename)
{
	int	fd;

	fd = open(filename, O_CREAT || O_APPEND);
	if (cmd->cout != 1)
		close(cmd->cout);
	cmd->cout = fd;
}

void	cmd_append_arg(t_cmd *cmd, char *word)
{
	cmd->argv = ft_arr_addback(cmd->argv, word);
}

// Нужно прикрутить разные названия для случая с несколькими хирдоками
void	heredoc_process(t_cmd *cmd, char *stopword)
{
	int			fd;
	int			writen;
	char		*line;
	int 		flag;
	const int	stopwordlen = ft_strlen(stopword);

	fd = open("heredoc", O_CREAT || O_APPEND);
	flag = 1;
	while (flag)
	{
		line = readline("> ");
		if (ft_strlen(line) == stopwordlen && ft_strncmp(stopword, line, stopwordlen) == 0)
			writen = write(fd, line, ft_strlen(line));
		else
			flag = 0 ;
	}
	if (writen) {};
	close(fd);
	cmd_change_cin(cmd, "/tmp/heredoc");
}

int	is_heredoc(char *word)
{
	if (ft_strlen(word) == 2 && ft_strncmp(HEREDOC, word, 2) == 0)
		return (1);
	return (0);
}

int	is_redirin(char *word)
{
	if (ft_strlen(word) == 1 && ft_strncmp(REDERIN, word, 1) == 0)
		return (1);
	return (0);
}

int	is_redirout(char *word)
{
	if (ft_strlen(word) == 1 && ft_strncmp(REDEROUT, word, 1) == 0)
		return (1);
	return (0);
}

int	is_redirout_append(char *word)
{
	if (ft_strlen(word) == 2 && ft_strncmp(REDEROUT_A, word, 2) == 0)
		return (1);
	return (0);
}

int	is_pipe(char *word)
{
	if (ft_strlen(word) == 1 && ft_strncmp("|", word, 1) == 0)
		return (1);
	return (0);
}

void	parse_to_cmds(t_mini *data)
{
	int		i;
	t_cmd	*cmd;
	char	**words;

	words = data->splited_line;
	data->cmds = malloc(sizeof(t_cmd *) * 1);
	*data->cmds = NULL;
	i = 0;
	while (words[i])
	{
		cmd = new_cmd(data->cmds, words[i]);
		i++;
		while (words[i] && is_pipe(words[i]) == 0)
		{
			if (is_heredoc(words[i]) && ++i)
				heredoc_process(cmd, words[i]);
			else if (is_redirin(words[i]) && ++i)
				cmd_change_cin(cmd, words[i]);
			else if (is_redirout(words[i]) && ++i)
				cmd_change_cout(cmd, words[i]);
			else if (is_redirout_append(words[i]) && ++i)
				cmd_change_cout_append(cmd, words[i]);
			else
				cmd_append_arg(cmd, words[i]);
			i++;
		}
		if (is_pipe(words[i]))
			i++;
	}
}
