/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:02:47 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/28 16:38:28 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

void	fill_executor_struct(t_executer_utils *utils, t_mini *mini)
{
	utils->pin = -1;
	utils->pout = -1;
	utils->current_fast = *mini->tokens;
	utils->current_slow = *mini->tokens;
}

void	close_pipe(int pin, int pout)
{
	if (pin != -1)
		close(pin);
	if (pout != -1)
		close(pout);
}
