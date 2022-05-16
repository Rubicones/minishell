//
// Created by rubicon on 29.04.2022.
//

#ifndef MINISHELL
# define MINISHELL

# include <unistd.h>
# include <stdio.h>
//# include <readline/readline.h>
//# include <readline/history.h>
# include <string.h>
# include <signal.h>
# include <stdlib.h>
# include "../src/libft/libft.h"

# define TEXT 1
# define HEREDOC 2 // <<
# define PIPE 3 // |
# define APPEND 4 // >>
# define REDIR_IN 5 // <
# define REDIR_OUT 6 // >

char	**ft_split_ppx(char *str, char c);

typedef struct s_split
{
	char	**big_str;
	int		k;
	int		word_counter;
	int		len;
	char	*str;
	char	c;
	int		i;
	int		j;
}				t_split;

#endif
