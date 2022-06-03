/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:08:12 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/03 19:08:18 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	int		i;
	t_mini	*data;

	if (argc != 2)
		return (0);
	data = malloc(sizeof(t_mini) * 1);
	data->line = argv[1];
	ms_splitline(data);
	i = -1;
	while (data->splited_line[++i])
		ft_printf("%s\n", data->splited_line[i]);
	return (0);
}
