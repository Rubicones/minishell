/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:43:33 by ejafer            #+#    #+#             */
/*   Updated: 2021/10/14 21:52:58 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	nstart;
	unsigned int	nlen;

	if (s1 == NULL || set == NULL)
		return (NULL);
	str = (char *) s1;
	while (*str && ft_strchr(set, *str))
		str++;
	nstart = str - (char *) s1;
	nlen = ft_strlen(str);
	if (nlen == 0)
		return (ft_substr(s1, 0, 0));
	str = (char *) s1 + ft_strlen(s1) - 1;
	while (ft_strchr(set, *str) && nlen-- > 0)
		str--;
	return (ft_substr(s1, nstart, nlen));
}
