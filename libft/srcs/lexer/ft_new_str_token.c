/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_str_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:54:16 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:54:20 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include "ft_str.h"

t_str_token		*ft_new_str_token(int type, char **str, void (*go_to)(char**))
{
	t_str_token	*new;
	char		*start;

	if (!str || !*str || !(new = (t_str_token*)ft_memalloc(sizeof(*new))))
		return (0);
	start = *str;
	go_to(str);
	if (!(new->value = ft_strsub(start, 0, *str - start)))
	{
		free(new);
		return (0);
	}
	new->type = type;
	return (new);
}
