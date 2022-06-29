/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envvars.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:21:47 by ejafer            #+#    #+#             */
/*   Updated: 2022/06/29 13:38:39 by ejafer           ###   ########.fr       */
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

char	*envvar_get(char *name, char **env);

#endif