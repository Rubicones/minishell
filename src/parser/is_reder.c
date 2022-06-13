/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:43:17 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/13 16:22:20 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int	is_heredoc(char	*word)
{
	if (ft_strlen(word) == ft_strlen(HEREDOC)
		&& ft_strncmp(word, HEREDOC, ft_strlen(HEREDOC)) == 0)
		return (1);
	return (0);
}

int	is_rederin(char	*word)
{
	if (ft_strlen(word) == ft_strlen(REDERIN)
		&& ft_strncmp(word, REDERIN, ft_strlen(REDERIN)) == 0)
		return (1);
	return (0);
}

int	is_rederout(char	*word)
{
	if (ft_strlen(word) == ft_strlen(REDEROUT)
		&& ft_strncmp(word, REDEROUT, ft_strlen(REDEROUT)) == 0)
		return (1);
	return (0);
}

int	is_rederout_a(char	*word)
{
	if (ft_strlen(word) == ft_strlen(REDEROUT_A)
		&& ft_strncmp(word, REDEROUT_A, ft_strlen(REDEROUT_A)) == 0)
		return (1);
	return (0);
}

int	is_reder(t_parser *data)
{
	char	*word;

	word = current_word(data);
	if (is_heredoc(word)
		|| is_rederin(word)
		|| is_rederout(word)
		|| is_rederout_a(word))
		return (1);
	return (0);
}
