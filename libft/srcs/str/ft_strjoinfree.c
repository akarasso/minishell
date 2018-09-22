/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:52:06 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:52:07 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strjoinfree(char *s1, char *s2, char flag)
{
	char	*new;
	int		len;

	len = (s1) ? ft_strlen(s1) : 0;
	len += (s2) ? ft_strlen(s2) : 0;
	if (!(new = ft_strnew(len)))
		return (0);
	if (s1)
		ft_strcat(new, s1);
	if (s2)
		ft_strcat(new, s2);
	if (s1 && (flag & LEFT))
		free(s1);
	if (s2 && (flag & RIGHT))
		free(s2);
	return (new);
}
