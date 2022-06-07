/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:47:49 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/07 17:02:57 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spliter.h"
#include "minishell.h"

int	current_letter_is_quotes(t_split_data *data)
{
	char	c;

	c = current_letter(data);
	if (c == QUOTES_D || c == QUOTES_S)
		return (1);
	return (0);
}

void	process_quotes(t_split_data *data)
{
	char	openquoute;

	openquoute = current_letter(data);
	data->index++;
	while (current_letter(data) && current_letter(data) != openquoute)
	{
		add_letter_to_current_word(data);
		data->index++;
	}
}
