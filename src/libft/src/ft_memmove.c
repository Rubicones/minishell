/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:55:30 by ejafer            #+#    #+#             */
/*   Updated: 2021/10/16 19:27:16 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy_rev(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *) dest + n - 1;
	s = (char *) src + n - 1;
	while (n-- > 0)
	{
		*d = *s;
		d--;
		s--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*d;
	char			*s;

	d = (char *) dest;
	s = (char *) src;
	if (d > s && d <= s + n)
		ft_memcpy_rev(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
