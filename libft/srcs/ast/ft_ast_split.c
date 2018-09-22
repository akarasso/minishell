/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:56:41 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 11:06:24 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ast_split(t_ast_node *node, t_dlst_elem *lst)
{
	node->right = ft_ast_new(node->token);
	node->left = ft_ast_new(lst->next);
	node->token = lst;
	ft_dlst_cut(lst, BEFORE | AFTER);
	return (1);
}
