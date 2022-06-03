/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:22:35 by ejafer            #+#    #+#             */
/*   Updated: 2021/10/14 17:08:48 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	const int	slen = ft_strlen(s);
	char		*tmp;

	tmp = (char *) malloc(sizeof(char) * slen + 1);
	if (tmp == NULL)
	{
		return (NULL);
	}
	ft_memcpy(tmp, s, slen + 1);
	return (tmp);
}
