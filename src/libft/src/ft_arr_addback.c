/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:29:51 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/07 14:38:20 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arr_addback(char **old_array, char *word)
{
	int			i;
	char		**new_array;
	const int	new_arrlen = (ft_arrlen(old_array) + 1);

	new_array = ft_arrnew(new_arrlen);
	if (!new_array)
		return (NULL);
	i = -1;
	while (old_array[++i])
		new_array[i] = old_array[i];
	new_array[i] = word;
	free(old_array);
	return (new_array);
}
