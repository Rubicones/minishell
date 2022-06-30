/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:21:13 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/30 21:35:10 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*remove_quotes(char *word)
{
	int		i;
	int		len;
	char	*result;

	len = ft_strlen(word) - 2;
	result = ft_strnew(len - 2);
	i = -1;
	while (++i < len)
		result[i] = word[i + 1];
	free(word);
	return (result);
}
