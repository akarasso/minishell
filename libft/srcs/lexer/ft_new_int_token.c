/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_int_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:54:11 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:54:12 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include "ft_char.h"
#include "ft_integer.h"

t_int_token	*ft_new_int_token(int type, char **str)
{
	t_int_token	*new;

	if (!(new = (t_int_token*)ft_memalloc(sizeof(*new))))
		return (0);
	new->type = type;
	if (str && *str)
	{
		new->value = ft_atoi(*str);
		if (**str == '-' || **str == '+')
			(*str)++;
		while (**str && ft_isdigit(**str))
			(*str)++;
	}
	else
		new->value = 0;
	return (new);
}
