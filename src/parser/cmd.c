/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:14:27 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/07 15:17:49 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*new_cmd(void **head, char *name)
{
	t_cmd	*tmp;

	tmp = malloc(sizeof(t_cmd) * 1);
	if (*head == NULL)
		*head = tmp;
	else
		cmd_pushback(head, tmp);
	tmp->name = name;
	tmp->argv = ft_arrnew(0);
	tmp->cin = 0;
	tmp->cout = 1;
	tmp->next = NULL;
	return (tmp);
}

void	cmd_pushback(void **head, t_cmd *cmd)
{
	t_cmd	*current;

	current = *head;
	while (current->next)
		current = current->next;
	current->next = cmd;
}

void	cmd_change_cin(t_cmd *cmd, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		throw_error();
	if (cmd->cout != 0)
		close(cmd->cout);
	cmd->cin = fd;
}

void	cmd_change_cout(t_cmd *cmd, char *filename)
{
	int	fd;

	fd = open(filename, O_CREAT || O_WRONLY);
	if (cmd->cout != 1)
		close(cmd->cout);
	cmd->cout = fd;
}

void	cmd_change_cout_append(t_cmd *cmd, char *filename)
{
	int	fd;

	fd = open(filename, O_CREAT || O_APPEND);
	if (cmd->cout != 1)
		close(cmd->cout);
	cmd->cout = fd;
}

void	cmd_append_arg(t_cmd *cmd, char *word)
{
	cmd->argv = ft_arr_addback(cmd->argv, word);
}
