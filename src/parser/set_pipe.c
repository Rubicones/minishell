/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:05:42 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/13 16:06:11 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_pipe(t_parser *data)
{
	t_token	*pipe_token;

	pipe_token = new_token(current_word(data), Pipe);
	token_push_back(data->head, pipe_token);
	data->current_command = NULL;
	data->command_is_set = 0;
	data->index++;
}
