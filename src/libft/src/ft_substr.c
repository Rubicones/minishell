/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:33:37 by ejafer            #+#    #+#             */
/*   Updated: 2021/10/14 21:50:36 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tmp;
	char			*str;
	size_t			index;
	size_t			slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		len = 0;
	tmp = (char *) malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	ft_memset(tmp, '\0', len + 1);
	str = (char *) s + start;
	index = 0;
	while (len-- > 0 && *str)
	{
		tmp[index] = *str;
		str++;
		index++;
	}
	return (tmp);
}
