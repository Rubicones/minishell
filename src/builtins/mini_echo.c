/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:51 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/21 14:13:25 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

void	mini_echo(t_command *cmd)
{
	int		i;
	char	*new_line;

	i = 0;
	new_line = "\n";
	if (ft_strncmp(cmd->argv[1], "-n", 3) == 0)
	{
		++i;
		new_line = "";
	}
	while (cmd->argv[++i])
	{
		printf("%s", cmd->argv[i]);
		if (cmd->argv[i + 1])
			printf(" ");
	}
	printf("%s", new_line);
}
