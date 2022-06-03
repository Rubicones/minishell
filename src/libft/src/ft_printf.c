/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:36:58 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/23 17:10:40 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(char *str, char c)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (ft_strlen(str) + 2));
	ft_strlcpy(tmp, str, ft_strlen(str) + 1);
	tmp[ft_strlen(str) + 1] = 0;
	tmp[ft_strlen(str)] = c;
	free(str);
	return (tmp);
}

void	ft_new_format(t_data *data)
{
	data->prc = 0;
	data->wdt = 0;
	data->ptr = 0;
}

void	ft_parse_format(t_data *data)
{
	ft_new_format(data);
	data->i++;
	while (!ft_strchr("sdx", data->format[data->i]))
	{
		if (data->format[data->i] == '.')
		{
			data->ptr = 1;
			data->i++;
		}
		while (ft_strchr("0123456789", data->format[data->i]))
		{
			if (data->ptr)
				data->prc = data->prc * 10 + data->format[data->i] - '0';
			else
				data->wdt = data->wdt * 10 + data->format[data->i] - '0';
			(data->i)++;
		}
	}
}

void	ft_make_str_from_format(t_data *data)
{
	char	*str;
	char	*tmp;

	ft_parse_format(data);
	str = NULL;
	if (data->format[data->i] == 's')
		str = ft_format_str(data, va_arg(data->args, char *));
	if (data->format[data->i] == 'd')
		str = ft_format_int(data, va_arg(data->args, int));
	if (data->format[data->i] == 'x')
		str = ft_format_hex(data, va_arg(data->args, unsigned int));
	tmp = ft_strjoin(data->result, str);
	free(data->result);
	free(str);
	data->result = tmp;
}

int	ft_printf(const char *format, ...)
{
	int		len;
	t_data	*data;

	data = malloc (sizeof(*data) * 1);
	data->result = malloc(sizeof(char) * 1);
	data->result[0] = 0;
	data->format = format;
	data->i = -1;
	va_start(data->args, format);
	while (data->format[++(data->i)])
	{
		if (data->format[data->i] == '%')
			ft_make_str_from_format(data);
		else
			data->result = ft_strjoin_char(data->result, format[data->i]);
	}
	len = ft_putstr_fd(data->result, 1);
	va_end(data->args);
	free(data->result);
	free(data);
	return (len);
}
