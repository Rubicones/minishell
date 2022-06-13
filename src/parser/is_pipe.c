/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:19:49 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/13 16:21:51 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int	is_pipe(t_parser *data)
{
	char	*word;

	word = current_word(data);
	if (ft_strlen(word) == ft_strlen(PIPE)
		&& ft_strncmp(word, PIPE, ft_strlen(PIPE)) == 0)
		return (1);
	return (0);
}
