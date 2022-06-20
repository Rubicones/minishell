/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:32:19 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/20 19:38:31 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spliter.h"
#include "minishell.h"
#include "libft.h"

void	post_process(t_split_data *data)
{
	return ;
}

void	split_line(t_mini *mini)
{
	t_split_data	*data;

	data = new_split_data(mini->line);
	while (current_letter(data))
	{
		if (current_letter_is_separator(data))
			process_separator(data);
		else if (current_letter_is_quotes(data))
			process_quotes(data);
		else
			process_word(data);
	}
	post_process(data);
	mini->splited_line = data->words;
	free(data);
}
