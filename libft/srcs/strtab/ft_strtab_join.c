/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:50:34 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:58:53 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtab_join(char **tab, char *key)
{
	char *res;

	res = ft_strdup(*tab);
	tab++;
	while (*tab)
	{
		res = ft_3strjoinfree(res, key, *tab, 0);
		tab++;
	}
	return (res);
}
