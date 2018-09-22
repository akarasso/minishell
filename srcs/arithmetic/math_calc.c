/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 10:13:33 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 10:14:22 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		math_node_operator(t_meval *meval, t_ast_node *node, t_chr_token *tkn)
{
	int	tmp;

	if (tkn->value == '+')
		return (math_calc(meval, node->left) + math_calc(meval, node->right));
	else if (tkn->value == '-')
		return (math_calc(meval, node->left) - math_calc(meval, node->right));
	else if (tkn->value == '*')
		return (math_calc(meval, node->left) * math_calc(meval, node->right));
	else if (tkn->value == '/')
	{
		tmp = math_calc(meval, node->right);
		if (!tmp)
		{
			ft_putendl("math_eval:: Try to divide by 0");
			meval->error = MATH_DIVIDE_ERROR;
			return (0);
		}
		return (math_calc(meval, node->left) / tmp);
	}
	else
		return (0);
}

int		math_node_parenthese(t_meval *meval, t_str_token *tkn)
{
	int ret;

	ft_strrmvchr(tkn->value);
	ft_strrmvchr(ft_strlastchr(tkn->value));
	if (!math_eval(tkn->value, &ret))
		return (ret);
	else
	{
		meval->error = MATH_SUBCALC_ERROR;
		return (0);
	}
}

int		math_calc(t_meval *meval, t_ast_node *node)
{
	t_chr_token *tkn;

	if (node && node->token && node->token->data)
	{
		tkn = (t_chr_token*)node->token->data;
		if (tkn && math_is_op(tkn->value))
			return (math_node_operator(meval, node, tkn));
		else if (tkn->type == MATH_PARENTHESE)
			return (math_node_parenthese(meval, node->token->data));
		else
			return ((t_int_token*)node->token->data)->value;
	}
	return (0);
}
