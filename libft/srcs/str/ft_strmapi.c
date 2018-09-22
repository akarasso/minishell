/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:54:19 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:52:17 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*new;
	char	*ptr;

	if (f && s)
	{
		index = 0;
		if (!(new = (char*)ft_memalloc(ft_strlen(s) + 1)))
			return (0);
		ptr = new;
		while (*s)
		{
			*ptr = f(index, *s);
			ptr++;
			s++;
			index++;
		}
		return (new);
	}
	return (0);
}
