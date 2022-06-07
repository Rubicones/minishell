/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:32:19 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/07 17:05:00 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spliter.h"
#include "minishell.h"
#include "libft.h"

void	split_line(t_mini *mini)
{
	t_split_data	*data;

	data = new_split_data(mini->line);
	while (current_letter(data))
	{
		if (current_letter_is_separator(data))
		{
			add_curent_word_to_words(data);
			process_separator(data);
		}
		else if (current_word_is_quotes(data))
			process_quotes(data);
		else
			add_letter_to_current_word(data);
	}
	mini->splited_line = data->words;
	free(data);
}
