/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:55:53 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 11:06:46 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst_elem	*ft_dlst_new_elem(void *data)
{
	t_dlst_elem *new;

	if (!(new = (t_dlst_elem*)ft_memalloc(sizeof(*new))))
		return (0);
	new->data = data;
	return (new);
}
