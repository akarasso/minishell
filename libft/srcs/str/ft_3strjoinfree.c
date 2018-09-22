/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3strjoinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:51:09 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:01:40 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

static void	ft_3strjoinfreefunc(char *s1, char *s2, char *s3, char flag)
{
	if (s1 && (flag & LEFT))
		free(s1);
	if (s2 && (flag & MID))
		free(s2);
	if (s3 && (flag & RIGHT))
		free(s3);
}

char		*ft_3strjoinfree(char *s1, char *s2, char *s3, char flag)
{
	char	*new;
	int		len;

	len = (s1) ? ft_strlen(s1) : 0;
	len += (s2) ? ft_strlen(s2) : 0;
	len += (s3) ? ft_strlen(s3) : 0;
	if (!(new = ft_strnew(len)))
	{
		ft_3strjoinfreefunc(s1, s2, s3, flag);
		return (0);
	}
	if (s1)
		ft_strcat(new, s1);
	if (s2)
		ft_strcat(new, s2);
	if (s3)
		ft_strcat(new, s3);
	ft_3strjoinfreefunc(s1, s2, s3, flag);
	return (new);
}
