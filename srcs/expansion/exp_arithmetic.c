#include "shell.h"

static char		*exp_arithmetic_pos(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (*str == '\\')
				str++;
			else if (*str == '\'')
				goto_next_quote(&str);
			else if (*str == '$' && *(str + 1) == '(' && *(str + 2) == '(')
				return (str);
			if (*str)
				str++;
		}
	}
	return (0);
}

static char		*exp_get_expr(char *s)
{
	char	*end;
	char	*ret;

	end = s;
	goto_end_arithmetic(&end);
	if ((ret = ft_strsub(s, 2, end - s - 2)))
	{
		if (ft_strcmp_end(ret, "))"))
		{
			free(ret);
			return (0);
		}
		ft_strrmvchr(ft_strlastchr(ret));
		ft_strrmvchr(ft_strlastchr(ret));
		return (ret);
	}
	return (0);
}

int				exp_arithmetic_exec(char *pos, char *expr, int *i, char **str)
{
	int		res;
	char	*strres;
	int		ret;

	*pos = 0;
	ret = 0;
	if (expr)
	{
		if (!math_eval(expr, &res) && (strres = ft_itoa(res)))
		{
			ret = ft_strlen(strres) - 1;
			*str = ft_3strjoinfree(*str, strres, &(*str)[*i + ft_strlen(expr) + 4], LEFT | MID);
		}
		ft_strdel(&expr);
	}
	return (ret);
}

void			exp_arithmetic(char **str)
{
	char	*start;
	char	*pos;
	int		i;

	start = *str;
	i = 0;
	while ((pos = exp_arithmetic_pos(&start[i])))
	{
		i = pos - start + 1;
		i += exp_arithmetic_exec(pos, exp_get_expr(&start[i]), &i, &start);
	}
	*str = start;
}
