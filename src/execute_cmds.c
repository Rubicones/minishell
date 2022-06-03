/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:48:36 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/03 21:40:59 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	execute_cmds(t_mini *mini)
{
	t_cmd *current;

	current = *mini->cmds;
	while (current)
	{
		printf("command name: %s\n", current->name);
		current = current->next;
	}
	//тут следует почистить структуру комманд
	*mini->cmds = NULL;
}