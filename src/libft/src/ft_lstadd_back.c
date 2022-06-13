/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:15:25 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/07 18:22:53 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *item)
{
	t_list	*tmp;

	if (lst == NULL || item == NULL)
		return ;
	tmp = ft_lstlast(*lst);
	if (tmp == NULL)
		*lst = item;
	else
		tmp->next = item;
}
