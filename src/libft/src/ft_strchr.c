/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:50:32 by ejafer            #+#    #+#             */
/*   Updated: 2021/10/14 19:50:15 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	size_t	ssize;

	str = (char *) s;
	ssize = ft_strlen(s) + 1;
	while (ssize-- > 0)
	{
		if (*str == (char) c)
			return (str);
		str++;
	}
	return (NULL);
}
