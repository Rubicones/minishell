/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:57:37 by ejafer            #+#    #+#             */
/*   Updated: 2021/10/14 22:15:01 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*tmp;
	unsigned int	index;

	if (s == NULL)
		return (NULL);
	str = (char *) s;
	tmp = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (tmp == NULL)
		return (NULL);
	ft_memset(tmp, '\0', ft_strlen(s) + 1);
	index = 0;
	while (*str)
	{
		tmp[index] = (*f)(index, *str);
		index++;
		str++;
	}
	return (tmp);
}
