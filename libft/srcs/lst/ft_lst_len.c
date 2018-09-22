/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:41:42 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:53:41 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

unsigned int	ft_lst_len(t_lst *container)
{
	unsigned int	len;
	t_lst_elem		*ptr;

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
