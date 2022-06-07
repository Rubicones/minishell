/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:45:43 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/07 15:11:21 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char	**append_pipe(char **old_array)
{
	char	*pipe;
	char	**new_array;

	pipe = ft_strnew(1);
	pipe[0] = '|';
	new_array = ft_arr_addback(old_array, pipe);
	return (new_array);
}

char	*brackets_content(char *str)
{
	int		i;
	char	*new_word;

	new_word = ft_strnew(1);
	new_word[0] = '"';
	i = -1;
	while (str[++i] && str[i] != '"')
		new_word = ft_str_addletter(new_word, str[i]);
	if (str[i] != '"')
		exit(-1);
	new_word = ft_str_addletter(new_word, '"');
	return (new_word);
}

void	split_line(t_mini *data)
{
	int		i;
	char	*line;
	char	*word;
	char	**words;

	line = data->line;
	word = ft_strnew(0);
	words = ft_arrnew(0);
	i = -1;
	while (line[++i])
	{
		if (line[i] == QUOTES_D)
		{
			if (ft_strlen(word) == 0)
			{
				word = brackets_content(line + i + 1);
				i += ft_strlen(word) - 1;
				words = ft_arr_addback(words, word);
				word = ft_strnew(0);
			}
		}
		else if (line[i] == PIPE)
		{
			if (ft_strlen(word))
				words = ft_arr_addback(words, word);
			words = append_pipe(words);
			word = ft_strnew(0);
		}
		else if (line[i] == SPACE)
		{
			if (ft_strlen(word))
				words = ft_arr_addback(words, word);
			word = ft_strnew(0);
			while (line[i + 1] == ' ')
				++i;
		}
		else
			word = ft_str_addletter(word, line[i]);
	}
	if (ft_strlen(word))
		words = ft_arr_addback(words, word);
	else
		free(word);
	data->splited_line = words;
}
