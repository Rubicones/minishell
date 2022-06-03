/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:47:01 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/19 18:47:01 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_width(char *str, int width)
{
	char	*tmp;

	while (ft_strlen(str) < width)
	{
		tmp = str;
		str = ft_strjoin(" ", str);
		free(tmp);
	}
	return (str);
}
