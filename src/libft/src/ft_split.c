/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:42:54 by ejafer            #+#    #+#             */
/*   Updated: 2021/10/16 22:25:18 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_missionabort(char **array, int index)
{
	index++;
	while (index-- > 0)
	{
		ft_memset(array[index], 0, ft_strlen(array[index]));
		free(array[index]);
	}
	free(array);
}

static unsigned int	ft_wordlen(char *s, char sep)
{
	unsigned int	len;

	len = 0;
	while (*s && *s != sep)
	{
		len++;
		s++;
	}
	return (len);
}

static void	ft_wordscpy(char **array, char *s, char c, int wnbr)
{
	unsigned int	index;
	unsigned int	wordlen;

	index = 0;
	while (*s && wnbr-- > 0)
	{
		wordlen = ft_wordlen(s, c);
		array[index] = (char *)malloc(sizeof(char) * (wordlen + 1));
		if (array[index] == NULL)
		{
			ft_missionabort(array, index);
			return ;
		}
		ft_memset(array[index], 0, wordlen + 1);
		ft_strlcpy(array[index], s, wordlen + 1);
		s = s + wordlen;
		while (*s && *s == c)
			s++;
		index++;
	}
}

static unsigned int	ft_wordsnbr(const char *s, char c)
{
	char			*str;
	unsigned int	counter;

	counter = 0;
	str = (char *) s;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			counter++;
			while (*str && *str != c)
				str++;
		}
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char			**array;
	char			*str;
	unsigned int	wnbr;

	str = (char *) s;
	if (str == NULL)
		return (NULL);
	if (*str == '\0' && c == '\0')
	{
		array = (char **) malloc(sizeof(char *) * 1);
		*array = NULL;
		return (array);
	}
	while (*str && *str == c)
		str++;
	wnbr = ft_wordsnbr(str, c);
	array = (char **) malloc(sizeof(char *) * (wnbr + 1));
	if (array == NULL)
		return (NULL);
	array[wnbr] = NULL;
	ft_wordscpy(array, str, c, wnbr);
	return (array);
}
