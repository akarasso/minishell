/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:50:16 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:50:16 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strtab.h"
#include "ft_mem.h"
#include "ft_str.h"

void	ft_strtab_del(char ***tab)
{
	int		i;
	char	**ptr;

	if (tab && *tab)
	{
		ptr = *tab;
		i = 0;
		while (ptr[i])
		{
			ft_strdel(&ptr[i]);
			i++;
		}
		free(ptr);
		*tab = 0;
	}
}
