/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:45 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/28 16:45:41 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

void	mini_exit(t_command *cmd, int ppid)
{
	int	status;

	if (!cmd->argv[1])
		status = g_status;
	else
	{
		status = ft_atoi(cmd->argv[1]);
		if (ft_nbrlen(status) != ft_strlen(cmd->argv[1]))
			status = 128;
		if (status < 0)
			status = -1;
	}
	kill(ppid, SIGUSR2);
	exit(status);
}
