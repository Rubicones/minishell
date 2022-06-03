/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:20:31 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/03 21:57:17 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char	**make_new_arrayy(int len)
{
	char	**new_words;

	new_words = malloc(sizeof(char *) * (len + 1));
	new_words[len] = NULL;
	return (new_words);
}

char	**append_wordd(char **old_array, char *word)
{
	int			i;
	char		**new_array;
	const int	new_arrlen = (ft_arrlen(old_array) + 1);

	new_array = make_new_arrayy(new_arrlen);
	i = -1;
	while (old_array[++i])
		new_array[i] = old_array[i];
	new_array[i] = word;
	free(old_array);
	return (new_array);
}

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
	tmp->argv = make_new_arrayy(0);
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

	fd = open(filename, O_WRONLY);
	if (cmd->cout != 1)
		close(cmd->cout);
	cmd->cout = fd;
}

void	cmd_change_cout_append(t_cmd *cmd, char *filename)
{
	int	fd;

	fd = open(filename, O_APPEND);
	if (cmd->cout != 1)
		close(cmd->cout);
	cmd->cout = fd;
}

void	cmd_append_arg(t_cmd *cmd, char *word)
{
	cmd->argv = append_wordd(cmd->argv, word);
}

// Нужно прикрутить разные названия для случая с несколькими хирдоками
void	heredoc_process(t_cmd *cmd, char *stopword)
{
	int			fd;
	int			writen;
	char		*line;
	const int	stopwordlen = ft_strlen(stopword);

	fd = open("/tmp/heredoc", O_WRONLY);
	while (1)
	{
		line = readline("> ");
		if (ft_strlen(line) == stopwordlen && ft_strncmp(stopword, line, stopwordlen) == 0)
		{
			writen = write(fd, line, ft_strlen(line));
			if (writen < 0)
				exit(-2);
		}
		else
			break ;
	}
	close(fd);
	cmd_change_cin(cmd, "/tmp/heredoc");
}

int	is_heredoc(char *word)
{
	if (ft_strlen(word) == 2 && ft_strncmp("<<", word, 2) == 0)
		return (1);
	return (0);
}

int	is_redirin(char *word)
{
	if (ft_strlen(word) == 1 && ft_strncmp("<", word, 1) == 0)
		return (1);
	return (0);
}

int	is_redirout(char *word)
{
	if (ft_strlen(word) == 1 && ft_strncmp(">", word, 1) == 0)
		return (1);
	return (0);
}

int	is_redirout_append(char *word)
{
	if (ft_strlen(word) == 2 && ft_strncmp(">>", word, 2) == 0)
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
			if (is_redirin(words[i]) && ++i)
				cmd_change_cin(cmd, words[i]);
			else if (is_redirout(words[i]) && ++i)
				cmd_change_cout(cmd, words[i]);
			else if (is_redirout_append(words[i]) && ++i)
				cmd_change_cout_append(cmd, words[i]);
			else
				cmd_append_arg(cmd, words[i]);
			i++;
		}
		if (words[i])
			i++;
	}
}
