/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_addletter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:45:14 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/07 14:45:33 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_addletter(char *old_word, char letter)
{
	int			i;
	char		*new_word;
	const int	new_wordlen = (ft_strlen(old_word) + 1);

	new_word = ft_strnew(new_wordlen);
	if (!new_word)
		return (NULL);
	i = -1;
	while (old_word[++i])
		new_word[i] = old_word[i];
	new_word[i] = letter;
	free(old_word);
	return (new_word);
}
