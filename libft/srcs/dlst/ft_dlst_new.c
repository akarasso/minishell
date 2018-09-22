/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:36:36 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:55:58 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlst_new(void *content)
{
	t_dlst *new;

	if (!(new = (t_dlst*)ft_memalloc(sizeof(*new))))
		return (0);
	if (content)
	{
		new->first = content;
		new->last = ft_dlst_getlast(content);
		new->len = ft_dlst_len(new);
	}
	return (new);
}
