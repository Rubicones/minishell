/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:45:43 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/03 21:32:45 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char	*make_new_word(int len)
{
	char	*new_word;

	new_word = malloc(sizeof(char) * (len + 1));
	new_word[len] = 0;
	return (new_word);
}

char	*append_letter(char *old_word, char letter)
{
	int			i;
	char		*new_word;
	const int	new_wordlen = (ft_strlen(old_word) + 1);

	new_word = make_new_word(new_wordlen);
	i = -1;
	while (old_word[++i])
		new_word[i] = old_word[i];
	new_word[i] = letter;
	free(old_word);
	return (new_word);
}

char	**make_new_array(int len)
{
	char	**new_words;

	new_words = malloc(sizeof(char *) * (len + 1));
	new_words[len] = NULL;
	return (new_words);
}

char	**append_word(char **old_array, char *word)
{
	int			i;
	char		**new_array;
	const int	new_arrlen = (ft_arrlen(old_array) + 1);

	new_array = make_new_array(new_arrlen);
	i = -1;
	while (old_array[++i])
		new_array[i] = old_array[i];
	new_array[i] = word;
	free(old_array);
	return (new_array);
}

char	**append_pipe(char **old_array)
{
	char	*pipe;
	char	**new_array;

	pipe = make_new_word(1);
	pipe[0] = '|';
	new_array = append_word(old_array, pipe);
	return (new_array);
}

char	*brackets_content(char *str)
{
	int		i;
	char	*new_word;

	new_word = make_new_word(1);
	new_word[0] = '"';
	i = -1;
	while (str[++i] && str[i] != '"')
		new_word = append_letter(new_word, str[i]);
	if (str[i] != '"')
		exit(-1);
	new_word = append_letter(new_word, '"');
	return (new_word);
}

void	split_line(t_mini *data)
{
	int		i;
	char	*line;
	char	*word;
	char	**words;

	line = data->line;
	word = make_new_word(0);
	words = make_new_array(0);
	i = -1;
	while (line[++i])
	{
		if (line[i] == '"')
		{
			if (ft_strlen(word) == 0)
			{
				word = brackets_content(line + i + 1);
				i += ft_strlen(word) - 1;
				words = append_word(words, word);
				word = make_new_word(0);
			}
		}
		else if (line[i] == '|')
		{
			if (ft_strlen(word))
				words = append_word(words, word);
			words = append_pipe(words);
			word = make_new_word(0);
		}
		else if (line[i] == ' ')
		{
			if (ft_strlen(word))
				words = append_word(words, word);
			word = make_new_word(0);
			while (line[i + 1] == ' ')
				++i;
		}
		else
			word = append_letter(word, line[i]);
	}
	if (ft_strlen(word))
		words = append_word(words, word);
	else
		free(word);
	data->splited_line = words;
}
