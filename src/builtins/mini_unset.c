/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:59 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/30 16:34:48 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "get_envvars.h"

char	**delete_var(char **env, int pos)
{
	int		i;
	char	**new_env;

	new_env = ft_arrnew(ft_arrlen(env) - 1);
	i = -1;
	while (++i < pos)
		new_env[i] = ft_strdup(env[i]);
	while (env[++i])
		new_env[i - 1] = ft_strdup(env[i]);
	return (new_env);
}

void	free_env(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		free(env[i]);
	free(env);
}

char	**unset_var(char *var, char **env)
{
	int		pos;
	char	**tmp;

<<<<<<< HEAD
	pos = envar_position(var, env);
	if (!env[pos])
=======
	i = envar_position(cmd->argv[1], env);
	if (!env[i])
	{
		g_status = 0;
>>>>>>> b4bcfb98bbd8741dc86c59be768c9b3a2103334c
		return (env);
	tmp = env;
	env = delete_var(env, pos);
	free_env(tmp);
	return (env);
}

char	**mini_unset(char **argv, char **env)
{
	int		i;

	i = 0;
	while (argv[++i])
		env = unset_var(argv[i], env);
	g_status = 0;
	return (env);
}
