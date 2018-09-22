/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_iter_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 20:09:53 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:55:36 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlst_iter_data(t_dlst *container, void (*exec_func)(void *))
{
	t_dlst_elem *ptr;

	if (!container || !container->first)
		return ;
	ptr = container->first;
	while (ptr)
	{
		exec_func(ptr->data);
		ptr = ptr->next;
	}
}

void	ft_dlstelem_iter_data(t_dlst_elem *elem, void (*exec_func)(void *))
{
	while (elem)
	{
		exec_func(elem->data);
		elem = elem->next;
	}
}
