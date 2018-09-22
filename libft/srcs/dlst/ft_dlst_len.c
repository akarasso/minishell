/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:41:42 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:05:24 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_dlst_len(t_dlst *container)
{
	unsigned int	len;
	t_dlst_elem		*ptr;

	len = 0;
	if (container)
	{
		ptr = container->first;
		while (ptr)
		{
			len++;
			ptr = ptr->next;
		}
	}
	return (len);
}
