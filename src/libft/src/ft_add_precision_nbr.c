/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_precision_nbr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:11:19 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/23 17:14:45 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_precision_nbr(char *str, int precision)
{
	char	*tmp;

	while (ft_strlen(str) < precision)
	{
		tmp = malloc(sizeof(char) * (ft_strlen(str) + 2));
		tmp[0] = '0';
		ft_strlcpy(tmp + 1, str, ft_strlen(str) + 1);
		free(str);
		str = tmp;
	}
	return (str);
}
