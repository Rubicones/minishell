/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:00:14 by ejafer            #+#    #+#             */
/*   Updated: 2021/10/16 19:37:28 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	
	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*d;
	char	*s;

	d = (char *) dst;
	s = (char *) src;
	while (n-- > 0)
	{
		*d = *s;
		d++;
		if ((unsigned char) *s == (unsigned char) c)
			return (d);
		s++;
	}
	return (NULL);
}
