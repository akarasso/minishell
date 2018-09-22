/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:55:06 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:52:29 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strncpy(char *dest, const char *src, size_t size)
{
	char *d;

	d = dest;
	while (*src && size > 0)
	{
		*d = *src;
		d++;
		src++;
		size--;
	}
	while (size > 0)
	{
		*d = '\0';
		d++;
		size--;
	}
	return (dest);
}
