/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_str_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 09:54:04 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 09:54:05 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void	ft_del_str_token(t_str_token **tkn)
{
	if (tkn && *tkn)
	{
		if ((*tkn)->value)
			free((*tkn)->value);
		free(*tkn);
		*tkn = 0;
	}
}
