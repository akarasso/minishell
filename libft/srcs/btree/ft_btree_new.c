/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:56:26 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:56:26 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree		*ft_btree_new(void *content)
{
	t_btree	*new;

	if (!(new = (t_btree*)ft_memalloc(sizeof(*new))))
		return (0);
	new->data = content;
	new->left = 0;
	new->right = 0;
	return (new);
}
