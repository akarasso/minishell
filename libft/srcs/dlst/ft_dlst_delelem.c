/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_delelem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:55:17 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:05:40 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlst_delelem(t_dlst *container, t_dlst_elem **elem,
	void (*f)(void *data))
{
	t_dlst_elem *prev;
	t_dlst_elem *next;

	if (elem && *elem)
	{
		prev = (*elem)->prev;
		next = (*elem)->next;
		ft_dlst_cut(*elem, BEFORE | AFTER);
		f((*elem)->data);
		free(*elem);
		*elem = 0;
		if (prev)
			prev->next = next;
		else
			container->first = next;
		if (next)
			next->prev = prev;
		else
			container->last = prev;
		container->len--;
	}
}

void	ft_dlstelem_del(t_dlst_elem **elem, void (*f)(void *data))
{
	t_dlst_elem *prev;
	t_dlst_elem *next;

	if (elem && *elem)
	{
		prev = (*elem)->prev;
		next = (*elem)->next;
		ft_dlst_cut(*elem, BEFORE | AFTER);
		f((*elem)->data);
		free(*elem);
		*elem = 0;
		if (prev)
			prev->next = next;
		if (next)
			next->prev = prev;
	}
}
