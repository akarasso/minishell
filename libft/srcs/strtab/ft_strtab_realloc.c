/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_realloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:50:53 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:50:53 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strtab.h"
#include "ft_mem.h"

char	**ft_strtab_realloc(char ***src, int len)
{
	char **new;

	if (!(new = ft_strtab_new(len + 1)))
		return (0);
	ft_strtab_cpy(*src, new);
	free(*src);
	*src = 0;
	*src = new;
	return (new);
}
