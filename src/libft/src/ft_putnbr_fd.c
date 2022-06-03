/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:01:42 by ejafer            #+#    #+#             */
/*   Updated: 2021/10/16 20:15:34 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	ft_putnbr_fd2(int n, int fd)
{
	int				len;
	char			buf[11];
	char			*iter;

	len = 11;
	while (len-- > 0)
		buf[len] = 0;
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	len = ft_intlen(n);
	while (len-- > 0)
	{
		buf[len] = n % 10 + '0';
		n /= 10;
	}
	iter = (char *) buf;
	while (*iter)
	{
		ft_putchar_fd(*iter, fd);
		iter++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
		ft_putnbr_fd2(n, fd);
}
