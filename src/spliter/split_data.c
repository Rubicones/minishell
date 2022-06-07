/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:08:57 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/07 17:56:21 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spliter.h"
#include "libft.h"

t_split_data	*new_split_data(char *line)
{
	t_split_data	*new_data;

	new_data = malloc(sizeof(t_split_data) * 1);
	new_data->line = line;
	new_data->index = 0;
	new_data->words = ft_arrnew(0);
	return (new_data);
}

char	current_letter(t_split_data	*data)
{
	return (data->line[data->index]);
}
