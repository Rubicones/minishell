/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:08:57 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/07 17:01:48 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spliter.h"
#include "minishell.h"

t_split_data	*new_split_data(char *line)
{
	t_split_data	*new_data;

	new_data = malloc(sizeof(t_split_data) * 1);
	new_data->line = line;
	new_data->index = -1;
	new_data->current_word = ft_strnew(0);
	new_data->words = ft_arrned(0);
	return (new_data);
}

void	add_letter_to_current_word(t_split_data	*data)
{
	data->current_word = ft_str_addletter(data->current_word,
			data->line[++data->index]);
}

void	add_curent_word_to_words(t_split_data *data)
{
	if (ft_strlen(data->current_word))
		data->words = ft_arr_addback(data->words, data->current_word);
	data->current_word = ft_strnew(0);
}

char	current_letter(t_split_data	*data)
{
	return (data->line[data->index]);
}
