/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:59:01 by ejafer            #+#    #+#             */
/*   Updated: 2021/10/16 21:37:23 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hstr;
	char	*nstr;
	char	*start;
	size_t	slen;

	hstr = (char *) haystack;
	nstr = (char *) needle;
	if (ft_strlen(needle) == 0 || hstr == nstr)
		return (hstr);
	while (*hstr && len-- > 0)
	{
		slen = len;
		start = hstr;
		while (*hstr == *nstr && slen-- > 0)
		{
			nstr++;
			if (*nstr == '\0')
				return (start);
			hstr++;
		}
		hstr = start;
		nstr = (char *) needle;
		hstr++;
	}
	return (NULL);
}
