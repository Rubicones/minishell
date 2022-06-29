/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:57 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/21 03:07:56 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_pwd(void)
{
	char	path[10000];

	if (getcwd(path, sizeof(path)) == NULL)
		perror(path);
	printf("%s\n", path);
}
