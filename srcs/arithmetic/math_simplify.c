#include "shell.h"

static	char	*goto_next_chr(char *s)
{
	while (*s && !ft_isdigit(*s) && *s != '(' && *s != ')' && !math_is_op(*s))
		s++;
	return (s);
}

void math_simplify(char *s)
{
	char	*tmp;

	while (*s)
	{
		if (*s == '-' && *(tmp = goto_next_chr(s + 1)) == '-')
		{
			*s = '+';
			ft_strrmvchr(tmp);
		}
		else if (*s == '+' && *(tmp = goto_next_chr(s + 1)) == '+')
			ft_strrmvchr(tmp);
		else if (*s == '+' && *(tmp = goto_next_chr(s + 1)) == '-')
			ft_strrmvchr(s);
		else if (*s == '-' && *(tmp = goto_next_chr(s + 1)) == '+')
			ft_strrmvchr(tmp);
		else
			s++;
	}
}
