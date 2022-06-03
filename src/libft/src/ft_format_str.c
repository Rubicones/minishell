/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:34:41 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/23 17:12:13 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_add_precision_str(char *str, int precision)
{
	char	*tmp;

	while (ft_strlen(str) > precision)
	{
		tmp = malloc(sizeof(char) * (ft_strlen(str)));
		ft_strlcpy(tmp, str, ft_strlen(str));
		tmp[ft_strlen(str) - 1] = 0;
		free(str);
		str = tmp;
	}
	return (str);
}

char	*ft_format_str(t_data *data, char *inp)
{
	char	*str;

	str = malloc(sizeof(char) * ft_strlen(inp));
	ft_strlcpy(str, inp, ft_strlen(inp) + 1);
	if (data->ptr)
		str = ft_add_precision_str(str, data->prc);
	str = ft_add_width(str, data->wdt);
	return (str);
}
