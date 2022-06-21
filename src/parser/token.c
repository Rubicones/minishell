/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:12:23 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/21 02:35:06 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

t_token	*new_token(char	*new_name, t_type new_type)
{
	t_token	*tmp;

	tmp = malloc(sizeof(t_token) * 1);
	tmp->name = new_name;
	tmp->type = new_type;
	tmp->argv = ft_arrnew(1);
	tmp->argv[0] = new_name;
	tmp->next = NULL;
	return (tmp);
}

void	clear_heredoc(t_token *token)
{
	unlink(token->argv[1]);
}

void	clear_token(t_token *token)
{
	int	i;

	i = -1;
	while (token->argv[++i])
		free(token->argv[i]);
	free(token->argv);
}

void	clear_tokens(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		if (token->type == Heredoc)
			clear_heredoc(token);
		clear_token(token);
		tmp = token;
		token = token->next;
		free(tmp);
	}
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
