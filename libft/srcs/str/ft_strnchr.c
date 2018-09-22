/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:52:23 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:52:23 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strnchr(char *str, char c, int n)
{
	while (*str && n > 0)
	{
		if (*str == c)
			return ((char*)str);
		n--;
		str++;
	}
	return (0);
}
