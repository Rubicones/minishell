/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:02:09 by ejafer            #+#    #+#             */
/*   Updated: 2021/10/14 19:15:53 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const size_t	dstlen = ft_strlen(dst);
	const size_t	srclen = ft_strlen(src);
	const size_t	appendlen = dstsize - dstlen - 1;
	char			*offset;

	if (dstsize < dstlen + 1)
		return (dstsize + srclen);
	offset = dst + dstlen;
	if (srclen < appendlen)
	{
		ft_memcpy(offset, src, srclen + 1);
	}
	else if (appendlen > 0)
	{
		ft_memcpy(offset, src, appendlen);
		*(offset + appendlen) = '\0';
	}
	return (dstlen + srclen);
}
