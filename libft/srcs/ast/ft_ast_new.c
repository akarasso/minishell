/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ast_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:56:38 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:56:51 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ast_node	*ft_ast_new(t_dlst_elem *tkn_lst)
{
	t_ast_node *new;

	if (!(new = (t_ast_node*)ft_memalloc(sizeof(*new))))
		return (0);
	new->token = tkn_lst;
	return (new);
}
