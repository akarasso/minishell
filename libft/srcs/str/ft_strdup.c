/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:53:06 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:51:55 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strdup(const char *src)
{
	char	*new;

	if (!src)
		return (0);
	if (!(new = (char*)malloc(sizeof(*new) * (ft_strlen(src) + 1))))
		return (0);
	ft_strcpy(new, src);
	return (new);
}
