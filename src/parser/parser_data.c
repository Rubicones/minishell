/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:35:25 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/13 16:24:50 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parser	*new_parser(char **words)
{
	t_parser	*tmp;

	tmp = malloc(sizeof(t_parser) * 1);
	tmp->command_is_set = 0;
	tmp->current_command = NULL;
	tmp->head = malloc(sizeof(t_token *) * 1);
	*tmp->head = NULL;
	tmp->index = 0;
	tmp->words = words;
	return (tmp);
}

char	*current_word(t_parser *data)
{
	return (data->words[data->index]);
}

int	is_command_set(t_parser *data)
{
	return (data->command_is_set);
}
