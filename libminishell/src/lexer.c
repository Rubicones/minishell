//
// Created by rubicon on 29.04.2022.
//

#include "../include/minishell.h"


int main(int argc, char **argv)
{
	char **s;
	char ***table;
	int i;

	if (argc > 1)
	{
		table = primary_check(argc, argv);
		i = 0;
		while (table[i])
		{
			printf("\n%s", table[i][1]);
			i++;
		}
	}

	return (0);
}

//gcc lexer.c libft/libft.a ft_split_quotes.c libft/ft_strlen.c libft/ft_isalnum.c primary_check.c
// ./a.out "qwerty"