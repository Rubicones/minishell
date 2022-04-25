/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:44:32 by ejafer            #+#    #+#             */
/*   Updated: 2022/04/25 17:15:02 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_mini
{
	int		argc;
	char	**argv;
	char	**env;
	char	**tokens;
	char	*line;
}	t_mini;

void	execute_line(t_mini *mini);
char	*mini_env(t_mini *mini);

#endif