/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:00:37 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/07 18:02:35 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITER_H
# define SPLITER_H

typedef struct s_split_data
{
	char	*line;
	int		index;
	char	**words;
}	t_split_data;

t_split_data	*new_split_data(char *line);
char			current_letter(t_split_data	*data);
int				current_letter_is_separator(t_split_data *data);
int				current_letter_is_quotes(t_split_data *data);
void			process_word(t_split_data *data);
void			process_separator(t_split_data *data);
void			process_quotes(t_split_data *data);

#endif