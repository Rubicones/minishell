/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:45 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/29 15:43:20 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

void	mini_exit(t_command *cmd)
{
	int	status;

	if (!cmd->argv[1])
		status = g_status;
	else
	{
		status = ft_atoi(cmd->argv[1]);
		if (status > 255)
			status %= 256;
		if (status < 0)
			status = 256 + (status % 256);
	}
	exit(status);
}
