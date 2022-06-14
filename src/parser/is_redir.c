/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:43:17 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/14 14:09:42 by ejafer           ###   ########.fr       */
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

int	is_redirin(char	*word)
{
	if (ft_strlen(word) == ft_strlen(REDIRIN)
		&& ft_strncmp(word, REDIRIN, ft_strlen(REDIRIN)) == 0)
		return (1);
	return (0);
}

int	is_redirout(char	*word)
{
	if (ft_strlen(word) == ft_strlen(REDIROUT)
		&& ft_strncmp(word, REDIROUT, ft_strlen(REDIROUT)) == 0)
		return (1);
	return (0);
}

int	is_redirout_a(char	*word)
{
	if (ft_strlen(word) == ft_strlen(REDIROUT_A)
		&& ft_strncmp(word, REDIROUT_A, ft_strlen(REDIROUT_A)) == 0)
		return (1);
	return (0);
}

int	is_redir(t_parser *data)
{
	char	*word;

	word = current_word(data);
	if (is_heredoc(word)
		|| is_redirin(word)
		|| is_redirout(word)
		|| is_redirout_a(word))
		return (1);
	return (0);
}
