/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:05:03 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/29 16:07:56 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "get_envvars.h"

void	free_paths(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}

char	*find_path(t_mini *mini, char *name)
{
	char	**paths;
	char	*path;
	int		i;
	char	*to_append;

	if (access(name, X_OK) == 0)
		return (ft_strdup(name));
	path = NULL;
	to_append = ft_strjoin("/", name);
	paths = ft_split(envvar_get("PATH", mini->env), ':');
	i = -1;
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], to_append);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
	}
	free(to_append);
	free_paths(paths);
	if (paths[i])
		return (path);
	return (NULL);
}
