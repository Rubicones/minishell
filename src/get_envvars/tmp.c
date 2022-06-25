/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:22:57 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/23 15:31:25 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	char	*tmp;
	char	**result;

	i = envar_position(name, env);
	if (env[i] == NULL)
		return (NULL);
	tmp = ft_strdup(env[i] + ft_strlen(name) + 1);
	result = ft_split(tmp, ':');
	free(tmp);
	return (result);
}

char	*resolve_envvar(char *word, char **env)
{
	int		i;
	char	**envvar;
	char	*result;

	envvar = envvar_get(word + 1, env);
	result = ft_strdup(envvar[0]);
	i = -1;
	while (envvar[++i])
		free(envvar[i]);
	free(envvar);
	free(word);
	return (result);
}

void	post_process(char **words, char	**env)
{
	int		i;

	i = -1;
	while (words[++i])
		if (words[i][0] == '$')
			words[i] = resolve_envvar(words[i], env);
}
