/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:28:12 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/07 14:29:11 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrnew(int len)
{
	char	**new_words;

	new_words = malloc(sizeof(char *) * (len + 1));
	if (!new_words)
		return (NULL);
	new_words[len] = NULL;
	return (new_words);
}
