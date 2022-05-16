/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:48:36 by ejafer            #+#    #+#             */
/*   Updated: 2022/04/25 17:15:06 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	execute_line(t_mini *mini)
{
	char *result;

	mini->tokens = ft_split(mini->line, ' ');
	if (ft_strncmp(mini->tokens[0], "env", 6) == 0)
		result = mini_env(mini);
	else
	{
		result = malloc(sizeof(char) * (ft_strlen(mini->tokens[0]) + 1));
		ft_strlcpy(result, mini->tokens[0], ft_strlen(mini->tokens[0]) + 1);
	}
	ft_printf("%s", result);
	free(result);
}