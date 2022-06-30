/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:53 by ejafer            #+#    #+#             */
/*   Updated: 2022/07/01 01:07:44 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"
#include "get_envvars.h"

char	**mini_cd(char **argv, char **env)
{
	if (ft_arrlen(argv) > 2)
		return (cd_no_arguments(env));
	if (ft_arrlen(argv) == 1)
		return (cd_no_arguments(env));
	else if (ft_arrlen(argv) == 2
		&& ft_strlen(argv[1]) == 1
		&& argv[1][0] == '-')
		return (cd_back(env));
	else if (ft_arrlen(argv) == 2
		&& argv[1][0] != '-')
		return (real_cd(ft_strdup(argv[1]), env));
	else
	{
		print_errormsg("cd: OLDPWD not set\n");
		return (env);
	}
	return (env);
}
