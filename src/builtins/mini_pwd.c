/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:57 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/18 13:36:51 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*mini_pwd(void)
{
	char	path[1000];

	if (getcwd(path, sizeof(path)) == NULL)
		perror(NULL);
	printf("%s\n", path);
	return (path);
}
