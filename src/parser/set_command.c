/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:05:47 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/25 19:30:51 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	set_command(t_parser *data)
{
	char	*name;
	t_token	*command_token;

	name = ft_strdup(current_word(data));
	if (ft_strchr("\'\"", name[0]))
		name = remove_quotes(name);
	command_token = new_token(name, Command);
	token_push_back(data->head, command_token);
	data->current_command = command_token;
	data->command_is_set = 1;
	data->index++;
}
