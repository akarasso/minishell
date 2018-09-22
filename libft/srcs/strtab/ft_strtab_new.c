/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:50:38 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:50:38 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

char	**ft_strtab_new(int len)
{
	char	**new;

	if (!(new = (char**)ft_memalloc(sizeof(*new) * (len + 1))))
		return (0);
	return (new);
}
