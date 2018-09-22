/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_clr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:54:54 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:54:58 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlst_clr(t_dlst *container, void (*f)(void *))
{
	t_dlst_elem *elem;
	t_dlst_elem *tmp;

	elem = container->first;
	while (elem)
	{
		tmp = elem->next;
		f(elem->data);
		free(elem);
		elem = tmp;
	}
	container->first = 0;
	container->last = 0;
	container->len = 0;
}
