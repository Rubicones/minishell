/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_separator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:10:25 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/14 14:08:17 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spliter.h"
#include "libft.h"
#include "minishell.h"

int	current_letter_is_separator(t_split_data *data)
{
	char	c;

	c = data->line[data->index];
	if (c == REDIRIN[0] || c == REDIROUT[0] || c == PIPE[0] || c == SPACE)
		return (1);
	return (0);
}

void	words_add(char *word, t_split_data *data)
{
	char	*word_to_add;

	word_to_add = ft_strdup(word);
	data->index += ft_strlen(word);
	data->words = ft_arr_addback(data->words, word_to_add);
}

void	process_separator(t_split_data *data)
{
	char	*line;
	int		i;

	i = data->index;
	line = data->line;
	if (ft_strncmp(HEREDOC, line + i, ft_strlen(HEREDOC)) == 0)
		words_add(HEREDOC, data);
	else if (ft_strncmp(REDIRIN, line + i, ft_strlen(REDIRIN)) == 0)
		words_add(REDIRIN, data);
	else if (ft_strncmp(REDIROUT_A, line + i, ft_strlen(REDIROUT_A)) == 0)
		words_add(REDIROUT_A, data);
	else if (ft_strncmp(REDIROUT, line + i, ft_strlen(REDIROUT)) == 0)
		words_add(REDIROUT, data);
	else if (ft_strncmp(PIPE, line + i, ft_strlen(PIPE)) == 0)
		words_add(PIPE, data);
	else
	{
		while (current_letter(data) == SPACE)
			data->index++;
	}
}
