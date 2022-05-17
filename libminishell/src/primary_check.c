//
// Created by rubicon on 17.05.2022.
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

char ***primary_check(int argc, char **argv)
{
	char **s;
	char ***table;
	int i;
	int j;
	int n;

	j = 0;
	n = 0;
	allocate_table(&table, 10);
	while (j < argc)
	{
		if (j > 0)
			free(s);
		s = ft_split_quotes(argv[j], ' ');
		i = 0;
		while (s[i])
		{
			part_check(s[i], &table, n);
			i++;
			n++;
		}
		j++;
	}
	return(table);
}