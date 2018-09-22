/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_cut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:55:02 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:55:05 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlst_cut(t_dlst_elem *lst, char flag)
{
	if ((flag & BEFORE) && lst->prev)
	{
		lst->prev->next = 0;
		lst->prev = 0;
	}
	if ((flag & AFTER) && lst->next)
	{
		lst->next->prev = 0;
		lst->next = 0;
	}
}
