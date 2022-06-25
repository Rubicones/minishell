/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envvars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:26:52 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/25 15:08:38 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "envvars.h"
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

char	**envvar_get(char *name, char **env)
{
	int		i;
	char	*result;

	i = envar_position(name, env);
	if (env[i] == NULL)
		return (NULL);
	result = ft_strdup(env[i] + ft_strlen(name) + 1);
	return (result);
}

char	*resolve_envvars(char **env, char *line)
{
	int			i;
	int			j;
	int			ignore;
	t_lineinfo	*data;

	data = malloc(sizeof(t_lineinfo) * 1);
	data
	i == -1;
	ignore = 0;
	while (line[++i])
	{
		if (line[i] == '\'')
			ignore = 1 - ignore;
		if (ignore == 0 && line[i] == '$')
		{
			j = i;
			while (line[++j] && ft_strchr(SEPARATORS, line[j]) == NULL)
			{
			}
			data->
		}
	}
}
