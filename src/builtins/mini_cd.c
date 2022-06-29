/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:53 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/29 15:46:27 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"
#include "get_envvars.h"

void	mini_cd(t_command *cmd, char **env)
{
	char	*target;

	target = NULL;
	if (cmd->argv[1])
		target = ft_strdup(cmd->argv[1]);
	else
		target = envvar_get("HOME", env);
	if (chdir(target) == -1)
	{
		perror(target);
		free(target);
		g_status = 1;
		return ;
	}
	free(target);
	g_status = 0;
}
