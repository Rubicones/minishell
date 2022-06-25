/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:21:13 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/25 19:28:10 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*remove_quotes(char *word)
{
	int		i;
	int		len;
	char	*result;

	len = ft_strlen(word) - 2;
	result = malloc(sizeof(char) * (len + 1));
	i = -1;
	while (++i < len)
		result[i] = word[i + 1];
	result[len] = 0;
	free(word);
	return (result);
}
