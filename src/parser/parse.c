/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:20:31 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/20 17:59:31 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	add_to_argv(t_parser *data)
{
	char	**argv;

	argv = data->current_command->argv;
	argv = ft_arr_addback(argv, current_word(data));
	data->current_command->argv = argv;
	data->index++;
}

void	parse(t_mini *mini)
{
	t_parser	*data;

	data = new_parser(mini->splited_line);
	while (current_word(data))
	{
		if (is_pipe(data))
			set_pipe(data);
		else if (is_redir(data))
			set_redir(mini, data);
		else if (is_command_set(data))
			add_to_argv(data);
		else
			set_command(data);
	}
	mini->tokens = data->head;
	free(data);
}
