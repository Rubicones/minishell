/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:51 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/16 20:20:58 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "libft.h"

void	mini_echo(t_command *cmd, char **argv)
{
	if (ft_strncmp(argv[1], "-n", 3) == 0 && ft_strncmp(argv[2], "(null)", 6) != 0)
		printf("%s", argv[2]);
	else
		printf("%s\n", argv[1]);
}

//echo -n "shit" | cat -e не работает
//echo "shit" | cat -e работает, но виснет почему-то