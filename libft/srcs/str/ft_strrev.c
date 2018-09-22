/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:13:21 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:52:53 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_str.h"

char	*ft_strrev(char *s)
{
	char	*srev;
	char	*ret;
	int		len;

	len = ft_strlen(s);
	if (!(srev = (char *)ft_memalloc(len + 1)))
		return (0);
	ret = srev;
	while (--len > -1)
	{
		*srev = s[len];
		srev++;
	}
	return (ret);
}
