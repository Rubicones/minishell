/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:42:15 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/07 14:43:26 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(int len)
{
	char	*new_word;

	new_word = malloc(sizeof(char) * (len + 1));
	if (!new_word)
		return (NULL);
	new_word[len] = 0;
	return (new_word);
}
