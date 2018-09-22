/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_find_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:50:23 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:50:23 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strtab.h"

int		ft_strtab_find_index(char **tab, char *value)
{
	int i;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i])
	{
		if (!ft_strcmp(tab[i], value))
			return (i);
		i++;
	}
	return (-1);
}
