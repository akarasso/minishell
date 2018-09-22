/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:44:43 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:44:43 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_env_del(char **tabe, char *key)
{
	int	klen;

	klen = ft_strlen(key);
	while (*tabe)
	{
		if (!ft_strncmp(*tabe, key, klen) && (*tabe)[klen] == '=')
		{
			ft_strtab_del_one(tabe, 0);
			return (1);
		}
		tabe++;
	}
	return (0);
}
