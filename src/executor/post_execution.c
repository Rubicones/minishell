/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 02:53:47 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/21 02:53:58 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	post_execution(t_mini *mini)
{
	clear_tokens(*mini->tokens);
	free(mini->splited_line);
	free(mini->tokens);
	mini->tokens = NULL;
}
