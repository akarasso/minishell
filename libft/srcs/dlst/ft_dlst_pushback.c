/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_pushback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 20:05:51 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:56:06 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst_elem		*ft_dlst_pushback(t_dlst *container, void *data)
{
	t_dlst_elem	*new;
	t_dlst_elem	*ptr;

	if (!data || !(new = ft_dlst_new_elem(data)))
		return (0);
	ptr = container->first;
	if (!ptr)
		container->first = new;
	else
	{
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		new->prev = ptr;
		ptr->next = new;
	}
	container->last = new;
	container->len++;
	return (new);
}
