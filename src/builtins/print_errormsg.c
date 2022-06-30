/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errormsg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:08:07 by ejafer            #+#    #+#             */
/*   Updated: 2022/07/01 01:11:27 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	print_errormsg(char *errormsg)
{
	if (write(STDERR_FILENO, errormsg, ft_strlen(errormsg)) < 0)
		perror("write");
}
