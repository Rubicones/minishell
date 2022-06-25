/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:23:41 by dgizzard          #+#    #+#             */
/*   Updated: 2022/06/25 19:38:19 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

int	is_builtin(t_command *cmd)
{
	int			i;
	const char	*builtins[] = {"echo", "cd", "pwd", "export",
		"unset", "env", "exit"};

	i = 0;
	while (i < 7)
	{
		if (ft_strncmp(cmd->name, builtins[i], ft_strlen(cmd->name)) == 0)
			return (1);
		i++;
	}
	return (0);
}
