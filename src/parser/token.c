/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:12:23 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/13 15:20:19 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*new_token(char	*new_name, t_type new_type)
{
	t_token	*tmp;

	tmp = malloc(sizeof(t_token) * 1);
	tmp->name = new_name;
	tmp->type = new_type;
	tmp->argv = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	token_push_back(t_token **head, t_token *to_push)
{
	t_token	*current;

	if (*head == NULL)
	{
		*head = to_push;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = to_push;
}
