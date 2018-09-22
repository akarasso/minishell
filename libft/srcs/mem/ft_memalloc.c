/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:49:52 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:53:23 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memalloc(size_t n)
{
	void *new;

	new = (void*)malloc(n);
	if (new)
		ft_bzero(new, n);
	return (new);
}
