/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:04:40 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/21 14:12:36 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char	*process_heredoc(char *stopword)
{
	char	*tmp;
	char	*result;
	char	*line;

	result = ft_strnew(0);
	line = ft_strnew(0);
	line = readline("> ");
	while (ft_strlen(line) != ft_strlen(stopword)
		|| ft_strncmp(line, stopword, ft_strlen(stopword)))
	{
		tmp = result;
		result = ft_strjoin(result, line);
		free(tmp);
		tmp = result;
		result = ft_strjoin(result, "\n");
		free(tmp);
		line = readline("> ");
	}
	return (result);
}

char	*generate_heredocname(t_mini *mini)
{
	char	*tmp;
	char	*result;
	char	*pid;
	char	*id;

	result = "/tmp/heredoc_";
	pid = ft_itoa(mini->pid);
	result = ft_strjoin(result, pid);
	free(pid);
	tmp = result;
	result = ft_strjoin(result, "_");
	free(tmp);
	id = ft_itoa(mini->heredocid++);
	tmp = result;
	result = ft_strjoin(result, id);
	free(id);
	free(tmp);
	return (result);
}

char	*set_heredoc(t_mini *mini, t_parser *data)
{
	int		fd;
	char	*fd_str;
	char	*filename;
	char	*result;
	char	*stopword;

	data->index++;
	stopword = current_word(data);
	result = process_heredoc(stopword);
	filename = generate_heredocname(mini);
	fd = open(filename, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(filename);
		exit(0);
	}
	if (write(fd, result, ft_strlen(result)) == -1)
	{
		fd_str = ft_itoa(fd);
		perror(fd_str);
		free(fd_str);
		exit(0);
	}
	close(fd);
	return (filename);
}

void	set_redir(t_mini *mini, t_parser *data)
{
	t_token	*reder_token;
	char	*filename;
	char	*redirtype;

	redirtype = current_word(data);
	filename = NULL;
	if (is_heredoc(redirtype))
	{
		filename = set_heredoc(mini, data);
		reder_token = new_token(redirtype, Heredoc);
	}
	else if (is_redirin(redirtype))
		reder_token = new_token(redirtype, Redirin);
	else if (is_redirout(redirtype))
		reder_token = new_token(redirtype, Redirout);
	else
		reder_token = new_token(redirtype, Redirout_a);
	if (is_heredoc(redirtype) == 0)
	{
		data->index++;
		filename = current_word(data);
	}
	reder_token->argv = ft_arr_addback(reder_token->argv, filename);
	token_push_back(data->head, reder_token);
	data->index++;
}
