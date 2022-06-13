/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:05:47 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/13 16:06:19 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_command(t_parser *data)
{
	t_token	*command_token;

	command_token = new_token(current_word(data), Command);
	token_push_back(data->head, command_token);
	data->current_command = command_token;
	data->command_is_set = 1;
	data->index++;
}
