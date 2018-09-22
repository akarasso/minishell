/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_strncmp_i.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:50:58 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:50:59 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strtab.h"

int		ft_strtab_strncmp_i(char **tab, char *value)
{
	int i;
	int last;

	i = 0;
	if (!tab)
		return (-1);
	last = -1;
	while (tab[i])
	{
		if (!ft_strncmp(tab[i], value, ft_strlen(tab[i])))
			last = i;
		i++;
	}
	return (last);
}
