/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:02:00 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/23 17:14:34 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_format_hex(t_data *data, unsigned int unbr)
{
	char	*str;

	str = ft_unbr_to_base(unbr, "0123456789abcdef");
	str = ft_add_precision_nbr(str, data->prc);
	str = ft_add_width(str, data->wdt);
	return (str);
}
