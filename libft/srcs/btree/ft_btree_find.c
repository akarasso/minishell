/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:56:22 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:07:08 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_btree_find(t_btree *tree, int (*func)(void*, void*), void *arg)
{
	int		ret;

	if (!tree)
		return (0);
	ret = func(tree->data, arg);
	if (!ret)
		return (tree->data);
	else if (ret <= 0)
		return (ft_btree_find(tree->left, func, arg));
	else
		return (ft_btree_find(tree->right, func, arg));
}
