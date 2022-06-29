/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:59 by ejafer            #+#    #+#             */
/*   Updated: 2022/04/25 16:10:38 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"
#include "get_envvars.h"

void	mini_unset(t_command *cmd, char **env)
{
	char	*target;
	int 	i;
	int 	env_len;

	env_len = 0;
	target = NULL;
	target = envvar_get("PWD", env);
	if (!target)
	{
		g_status = 1;
		free(target);
		return ;
	}
	i = envar_position(cmd->argv[1], env);
	while (env[env_len])
		env_len++;
	while (i + 1 < env_len)
	{
		env[i] = env[i + 1];
		i++;
	}
	free(target);
	g_status = 0;
}
