/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_del_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:50:11 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:50:12 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_str.h"

void	ft_strtab_del_one(char **tab, int index)
{
	free(tab[index]);
	index++;
	while (tab[index])
	{
		tab[index - 1] = tab[index];
		index++;
	}
	tab[index - 1] = 0;
}
