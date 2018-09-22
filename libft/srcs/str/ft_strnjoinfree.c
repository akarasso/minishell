/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:52:46 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:52:46 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strnjoin(char *src, int lsrc, char *right, char flag)
{
	char	*new;
	int		len;

	len = 0;
	len += (src) ? ft_strlen(src) : 0;
	len += (right) ? ft_strlen(right) : 0;
	if (!(new = ft_strnew(len)))
		return (0);
	if (src)
		ft_strncat(new, src, lsrc);
	if (right)
		ft_strcat(new, right);
	if (src)
		ft_strcat(new, src + lsrc + 1);
	if (flag & LEFT)
		free(src);
	if (flag & RIGHT)
		free(right);
	return (new);
}
