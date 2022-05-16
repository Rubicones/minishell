//
// Created by rubicon on 29.04.2022.
//

#include "../include/minishell.h"
#include "libft/libft.h"

void specific_cases(char *part, char**** arr, int n)
{
	if (part[0] == '|')
		(*arr)[n][0][0] = PIPE;
	else if (part[0] == '>' && part[1] == '>')
	{
		(*arr)[n][0][0] = APPEND;
		(*arr)[n][1] = ">>";
	}
	else if (part[0] == '<' && part[1] == '<')
	{
		(*arr)[n][0][0] = HEREDOC;
		(*arr)[n][1] = "<<";
	}
	else if (part[0] == '<')
		(*arr)[n][0][0] = REDIR_IN;
	else if (part[0] == '>')
		(*arr)[n][0][0] = REDIR_OUT;
	if (!((*arr)[n][1][0]))
		(*arr)[n][1][0] = part[0];

}

void text_case(char *part, char**** arr, int n)
{
	int j;

	j = 0;
	(*arr)[n][0][0] = TEXT;
	while(part[j])
	{
		(*arr)[n][1][j] = part[j];
		j++;
	}
}

void part_check(char *part, char**** arr, int n)
{
	if (part[0] == '|' || part[0] == '<' || part[0] == '>')
		specific_cases(part, arr, n);
	else if (ft_isalnum(part[0]))
		text_case(part, arr, n);
}

void allocate_table(char**** arr, int h)
{
	int i;

	i = 0;
	*arr = (char ***)malloc(h * sizeof(char**));
	while (i < h)
	{
		(*arr)[i] = (char **)malloc(2 * sizeof(char*));
		(*arr)[i][0] = (char *)malloc(10000 * sizeof(char));
		(*arr)[i][1] = (char *)malloc(10000 * sizeof(char));
		i++;
	}
}

int main(int argc, char **argv)
{
	char **s;
	char ***table;
	int i;
	int j;


	j = 0;
	i = 0;
	if (argv[1])
	{
		allocate_table(&table, 30); // argc as second arg
		s = ft_split_ppx(argv[1], ' ');
		while (s[i])
		{
			part_check(s[i], &table, i);
			printf("\n%s", table[i][1]);
			i++;

		}
	}

	return (0);
}


//gcc lexer.c libft/libft.a ft_split_quotes.c libft/ft_strlen.c
// ./a.out "qwerty"