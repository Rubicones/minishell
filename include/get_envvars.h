/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envvars.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:21:47 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/25 15:06:08 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_ENVVARS_H
# define GET_ENVVARS_H

# define SEPARATORS " 	<>|$\"\'"

typedef struct s_lineinfo
{
	char	*processed;
	char	*raw;
}	t_lineinfo;

#endif