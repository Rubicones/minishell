/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:49 by ejafer            #+#    #+#             */
/*   Updated: 2022/04/26 17:56:51 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char	*mini_env(t_mini *mini)
{
	char	*result;
	char	*tmp;
	int		i;

	i = -1;
	result = malloc(sizeof(char) * 1);
	result[0] = 0;
	while (mini->env[++i])
	{
		tmp = result;
		result = ft_strjoin(result, mini->env[i]);
		free(tmp);
		tmp = result;
		result = ft_strjoin(result, "\n");
		free(tmp);
	}
	return (result);
}
