#include "shell.h"

int		math_push_number(t_dlst	*lexer, char **str)
{
	t_int_token *tkn;

	if (!(tkn = ft_new_int_token(MATH_NUMBER, str)))
		return (0);
	if (!(ft_dlst_pushback(lexer, tkn)))
	{
		free(tkn);
		return (0);
	}
	return (1);
}

static	void goto_end_parentheses(char **str)
{
	int stack;

	stack = 0;
	while (**str)
	{
		if (**str == '(')
			stack++;
		if (**str == ')')
			stack--;
		(*str)++;
		if (!stack)
			break ;
	}
}

int		math_push_parenthese(t_dlst	*lexer, char **str)
{
	t_str_token *tkn;

	if (!(tkn = ft_new_str_token(MATH_PARENTHESE, str, goto_end_parentheses)))
		return (0);
	if (*tkn->value != '(' || *(ft_strlastchr(tkn->value)) != ')')
	{
		free(tkn->value);
		free(tkn);
		ft_putendl("math_eval:: error parenthesis");
		return (0);
	}
	if (!(ft_dlst_pushback(lexer, tkn)))
	{
		free(tkn);
		return (0);
	}
	return (1);
}

int		math_push_preparenthese(t_dlst	*lexer, char **str)
{
	char		*old;
	t_int_token *itkn;
	t_chr_token *optkn;

	old = *str;
	if (!(itkn = ft_new_int_token(MATH_NUMBER, str)))
		return (0);
	itkn->value = (*old == '+') ? 1 : -1;
	if (!ft_dlst_pushback(lexer, itkn))
	{
		free(itkn);
		return (0);
	}
	if (!(optkn = ft_new_chr_token(MATH_OPERATOR, str)))
		return (0);
	if (!ft_dlst_pushback(lexer, optkn))
	{
		free(optkn);
		return (0);
	}
	optkn->value = '*';
	*str = old + 1;
	return (1);
}


int		math_push_op(t_dlst	*lexer, char **str)
{
	t_chr_token *tkn;

	if (!(tkn = ft_new_chr_token(MATH_OPERATOR, str)))
		return (0);
	if (!ft_dlst_pushback(lexer, tkn))
	{
		free(tkn);
		return (0);
	}
	return (1);
}
