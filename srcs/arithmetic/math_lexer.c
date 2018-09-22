/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:13:43 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:20:09 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		math_is_op(char c)
{
	if (c == '-' || c == '+' || c == '/' || c == '%' || c == '*')
		return (1);
	return (0);
}

int		math_push_token(t_dlst *lexer, char **str, char *tmp)
{
	if (*tmp && math_is_op(**str))
		return (math_push_op(lexer, str));
	else if (**str == '(' || **str == ')')
		return (math_push_parenthese(lexer, str));
	else if (ft_isdigit(**str) || ((**str == '-' || **str == '+')
			&& ft_isdigit(*((*str) + 1))))
		return (math_push_number(lexer, str));
	else if ((**str == '-' || **str == '+') && *(*str + 1) == '(')
		return (math_push_preparenthese(lexer, str));
	else if (**str > 32)
	{
		printf("math_eval:: error near '%.5s'\n", *str);
		return (0);
	}
	return (-1);
}

int		math_parser_error(t_dlst_elem *lst, t_chr_token *tkn)
{
	if (tkn->type == MATH_OPERATOR)
	{
		if (!lst->next || !lst->prev)
		{
			printf("math_eval:: error near '%c'\n", tkn->value);
			return (0);
		}
		if (((t_int_token*)lst->next->data)->type == MATH_OPERATOR
			|| ((t_int_token*)lst->prev->data)->type == MATH_OPERATOR)
		{
			printf("math_eval:: error near '%c'\n", tkn->value);
			return (0);
		}
	}
	if (tkn->type == MATH_NUMBER)
	{
		if (lst->next && ((t_int_token*)lst->next->data)->type == MATH_NUMBER)
		{
			printf("math_eval:: error near '%d'\n",
				((t_int_token*)lst->next->data)->value);
			return (0);
		}
	}
	return (1);
}

int		math_parser(t_dlst_elem *lst)
{
	while (lst)
	{
		if (!math_parser_error(lst, lst->data))
			return (0);
		lst = lst->next;
	}
	return (1);
}

int		math_lexer(t_meval *math_eval, char *str)
{
	char		tmp;
	int			ret;
	t_chr_token	*tkn;

	tmp = 0;
	while (*str)
	{
		ret = math_push_token(math_eval->lexer, &str, &tmp);
		if (math_eval->lexer->last)
		{
			tkn = math_eval->lexer->last->data;
			tmp = (tkn->type == MATH_OPERATOR) ? 0 : 1;
		}
		if (!ret)
		{
			math_eval->error = MATH_MALLOC_ERROR;
			return (0);
		}
		if (ret == -1)
			str++;
	}
	return (math_parser(math_eval->lexer->first));
}
