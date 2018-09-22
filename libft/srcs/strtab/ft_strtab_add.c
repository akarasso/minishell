/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:49:58 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:49:59 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strtab_add(char ***tab, char *new)
{
	int		len;
	char	**newtab;

	if (!*tab)
		return (0);
	len = ft_strtab_len(*tab);
	if (!new)
		return (0);
	if (!(newtab = ft_strtab_realloc(tab, len + 1)))
	{
		ft_strtab_del(&newtab);
		return (0);
	}
	*tab = newtab;
	newtab[len] = new;
	return (1);
}
