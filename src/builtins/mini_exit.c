/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:45 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/30 20:05:28 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

void	mini_exit(t_command *cmd)
{
	int		status;
	char	*errormsg;
	char	*tmp;

	if (!cmd->argv[1])
		status = g_status;
	else
	{
		status = ft_atoi(cmd->argv[1]);
		if (ft_strlen(cmd->argv[1]) != ft_nbrlen(status)
			|| cmd->argv[1][ft_strlen(cmd->argv[1])] - '0' != status % 10)
		{
			errormsg = ft_strjoin("exit: Illegal number: ", cmd->argv[1]);
			tmp = errormsg;
			errormsg = ft_strjoin(errormsg, "\n");
			free(tmp);
			if (write(STDERR_FILENO, errormsg, ft_strlen(errormsg)) < 0)
				perror(errormsg);
			free(errormsg);
			g_status = 2;
			return ;
		}
		if (status > 255)
			status %= 256;
		if (status < 0)
			status = 256 + (status % 256);
	}
	exit(status);
}
