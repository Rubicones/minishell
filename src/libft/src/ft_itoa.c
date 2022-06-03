/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:05:25 by ejafer            #+#    #+#             */
/*   Updated: 2021/10/18 18:54:52 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_minint(void)
{
	char	*tmp;

	tmp = (char *) malloc(sizeof(char) * 13);
	if (tmp == NULL)
		return (NULL);
	ft_strlcpy(tmp, "-2147483648", 13);
	return (tmp);
}

static unsigned int	ft_intlen(int n)
{
	int	len;

	n /= 10;
	len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa_rest(int n)
{
	char			*tmp;
	unsigned int	nlen;
	int				sign;

	sign = 0;
	nlen = ft_intlen(n);
	if (n < 0)
	{
		n = -n;
		sign = 1;
	}
	tmp = (char *) malloc(sizeof(char) * (sign + nlen + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[sign + nlen] = '\0';
	while (nlen-- > 0)
	{
		tmp[nlen + sign] = n % 10 + '0';
		n /= 10;
	}
	if (sign == 1)
		tmp[0] = '-';
	return (tmp);
}

char	*ft_itoa(int n)
{
	if (n == -2147483648)
		return (ft_itoa_minint());
	return (ft_itoa_rest(n));
}
