/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:53:44 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:53:45 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include "ft_mem.h"

t_lst_elem	*ft_lst_new_elem(void *data)
{
	t_lst_elem *new;

	if (!(new = (t_lst_elem*)ft_memalloc(sizeof(t_lst_elem*))))
		return (0);
	new->data = data;
	return (new);
}
