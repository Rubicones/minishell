/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbr_to_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:04:18 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/23 17:12:53 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_unbr_in_base_len(unsigned int unbr, int baselen)
{
	int	len;

	len = 0;
	while (++len && unbr)
		unbr /= baselen;
	return (len);
}

char	*ft_unbr_to_base(unsigned int unbr, char *base)
{
	char		*str;
	int			strlen;
	const int	baselen = ft_strlen(base);

	strlen = ft_unbr_in_base_len(unbr, baselen);
	str = malloc(sizeof(char) * (strlen + 1));
	str[strlen] = 0;
	while (strlen--)
	{
		str[strlen] = base[unbr % baselen];
		unbr /= baselen;
	}
	return (str);
}
