/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_eval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:13:39 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:14:58 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_meval	*init_meval(int *res)
{
	t_meval *new;

	if (!res || !(new = (t_meval*)malloc(sizeof(*new))))
		return (0);
	if (!(new->lexer = ft_dlst_new(0)))
	{
		free(new);
		return (0);
	}
	new->result = res;
	new->ast = 0;
	new->error = 0;
	return (new);
}

int		math_eval(char *s, int *res)
{
	t_meval *meval;
	int		ret;

	if (!s || !(meval = init_meval(res)))
		return (0);
	math_simplify(s);
	if (!math_lexer(meval, s) || !(meval->ast = math_ast(meval->lexer)))
		ret = MATH_MALLOC_ERROR;
	else
	{
		*meval->result = math_calc(meval, meval->ast);
		ret = meval->error;
	}
	math_destroy(meval);
	return (ret);
}
