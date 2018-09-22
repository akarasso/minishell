/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_rsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:56:35 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:56:48 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ast_rsplit(t_ast_node *node, t_dlst_elem *lst)
{
	node->right = ft_ast_new(lst->next);
	node->left = ft_ast_new(node->token);
	node->token = lst;
	ft_dlst_cut(lst, BEFORE | AFTER);
	return (1);
}
