/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:55:24 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/23 17:13:14 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_char_front(char *str, char c)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (ft_strlen(str) + 2));
	ft_strlcpy(tmp + 1, str, ft_strlen(str) + 1);
	tmp[ft_strlen(str) + 1] = 0;
	tmp[0] = c;
	free(str);
	return (tmp);
}

char	*ft_format_int(t_data *data, long nbr)
{
	char	sign;
	char	*str;

	sign = 0;
	if (nbr < 0)
	{
		sign = '-';
		nbr = -nbr;
	}
	str = ft_itoa(nbr);
	str = ft_add_precision_nbr(str, data->prc);
	if (sign)
		str = ft_strjoin_char_front(str, sign);
	str = ft_add_width(str, data->wdt);
	return (str);
}
