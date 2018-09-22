/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:50:19 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:50:20 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strtab.h"

char	**ft_strtab_dup(char **src)
{
	char	**new;
	int		len;
	int		i;

	if (!src)
		return (0);
	len = ft_strtab_len(src);
	if (!(new = ft_strtab_new(len)))
		return (0);
	i = 0;
	while (src[i])
	{
		if (!(new[i] = ft_strdup(src[i])))
		{
			ft_strtab_del(&new);
			return (0);
		}
		i++;
	}
	return (new);
}
