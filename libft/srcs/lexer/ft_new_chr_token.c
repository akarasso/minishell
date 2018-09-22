/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_chr_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:54:07 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:54:07 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_chr_token	*ft_new_chr_token(int type, char **str)
{
	t_chr_token	*new;

	if (!str || !*str || !(new = (t_chr_token*)ft_memalloc(sizeof(*new))))
		return (0);
	new->type = type;
	new->value = **str;
	(*str)++;
	return (new);
}
