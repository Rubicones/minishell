/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:51:41 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/07 18:01:48 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spliter.h"
#include "libft.h"

void	process_word(t_split_data *data)
{
	char	*word;

	word = ft_strnew(0);
	while (current_letter(data) && current_letter_is_separator(data) == 0)
	{
		word = ft_str_addletter(word, current_letter(data));
		data->index++;
	}
		data->words = ft_arr_addback(data->words, word);
}
