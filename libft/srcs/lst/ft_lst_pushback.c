/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 20:05:51 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:53:50 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

int		ft_lst_pushback(t_lst *container, void *data)
{
	t_lst_elem	*new;
	t_lst_elem	*ptr;

	if (!data || !(new = ft_lst_new_elem(data)))
		return (0);
	ptr = container->first;
	if (!ptr)
		container->first = new;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	container->last = new;
	container->len++;
	return (1);
}
