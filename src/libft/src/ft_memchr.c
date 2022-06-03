/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:10:10 by ejafer            #+#    #+#             */
/*   Updated: 2021/10/16 19:38:49 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	uc;

	uc = (unsigned char) c;
	src = (unsigned char *) s;
	while (n-- > 0)
	{
		if (*src == uc)
			return (src);
		src++;
	}
	return (NULL);
}
