/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:54:02 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:52:15 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

size_t	ft_strlen(const char *src)
{
	char *ptr;

	ptr = (char*)src;
	while (*ptr)
		ptr++;
	return (ptr - src);
}
