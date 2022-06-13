/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_reder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:04:40 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/13 16:25:52 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	set_reder(t_parser *data)
{
	t_token	*reder_token;
	char	*word;

	word = current_word(data);
	if (is_heredoc(word))
		reder_token = new_token(word, Heredoc);
	else if (is_rederin(word))
		reder_token = new_token(word, Rederin);
	else if (is_rederout(word))
		reder_token = new_token(word, Rederout);
	else
		reder_token = new_token(word, Rederout_a);
	data->index++;
	reder_token->argv = ft_arrnew(0);
	reder_token->argv = ft_arr_addback(reder_token->argv, current_word(data));
	token_push_back(data->head, reder_token);
	data->index++;
}
