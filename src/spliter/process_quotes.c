/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:47:49 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/20 19:37:43 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spliter.h"
#include "minishell.h"
#include "libft.h"

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
	char	*word;
	char	openquoute;

	openquoute = current_letter(data);
	word = ft_strnew(1);
	word[0] = openquoute;
	data->index++;
	while (current_letter(data) && current_letter(data) != openquoute)
	{
		word = ft_str_addletter(word, current_letter(data));
		data->index++;
	}
	word = ft_str_addletter(word, openquoute);
	data->words = ft_arr_addback(data->words, word);
	data->index++;
}
