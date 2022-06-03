/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:13:39 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/23 16:24:15 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	nstr = (char *) malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (nstr == NULL)
		return (NULL);
	ft_strlcpy(nstr, s1, s1_len + 1);
	ft_strlcat(nstr, s2, s1_len + s2_len + 1);
	return (nstr);
}
