/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envvars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:26:52 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/25 19:40:45 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_envvars.h"
#include "minishell.h"
#include "libft.h"

int	envar_position(char *name, char **env)
{
	int	i;
	int	namelen;

	i = -1;
	namelen = ft_strlen(name);
	while (env[++i])
		if (ft_strlen(env[i]) > namelen
			&& env[i][namelen] == '='
			&& ft_strncmp(env[i], name, namelen) == 0)
			break ;
	return (i);
}

char	*envvar_get(char *name, char **env)
{
	int		i;
	char	*result;

	i = envar_position(name, env);
	if (env[i] == NULL)
		return (NULL);
	result = ft_strdup(env[i] + ft_strlen(name) + 1);
	return (result);
}

char	*join_envvar(char **env, char *result, char *line, int len)
{
	int		i;
	char	*tmp;
	char	*envvar_name;
	char	*envvar_val;

	envvar_name = malloc(sizeof(char) * (len + 1));
	envvar_name[len] = 0;
	i = -1;
	while (++i < len)
		envvar_name[i] = line[i];
	envvar_val = envvar_get(envvar_name, env);
	free(envvar_name);
	if (envvar_val)
	{
		tmp = result;
		result = ft_strjoin(result, envvar_val);
		free(envvar_val);
		free(tmp);
	}
	return (result);
}

//Отрефакторить для норминетта. Возможно через структуру
void	resolve_envvars(t_mini *mini)
{
	int			i;
	int			j;
	int			ignore;
	char		*result;

	result = ft_strnew(0);
	i = 0;
	ignore = 0;
	while (mini->line[i])
	{
		while (mini->line[i] && (mini->line[i] != '$' || ignore))
		{
			if (mini->line[i] == '\'')
				ignore = 1 - ignore;
			result = ft_str_addletter(result, mini->line[i]);
			i++;
		}
		if (mini->line[i] == '$')
		{
			j = 1;
			while (mini->line[i + j]
				&& !ft_strchr(SEPARATORS, mini->line[i + j]))
				j++;
			result = join_envvar(mini->env, result, mini->line + i + 1, j - 1);
			i += j;
		}
	}
	mini->line = result;
}