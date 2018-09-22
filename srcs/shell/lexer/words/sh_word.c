#include "shell.h"

int		is_word(char *str)
{
	return (ft_isprint(*str) && !is_space(*str)) ? 1 : 0;
}

void	goto_end_arithmetic(char **s)
{
	int stack;

	stack = 0;
	while (**s)
	{
		if (**s == '(')
			stack++;
		if (**s == ')')
			stack--;
		if (stack < 3 && !ft_strncmp("))", *s, 2))
		{
			(*s) += 2;
			break ;
		}
		(*s)++;
	}
}

void	goto_end_word(char **str)
{
	char	*ptr;

	ptr = *str;
	while (*ptr && ft_strtab_strncmp_i(g_shell_op, ptr) == -1
		&& is_redirect(ptr) == -1 && !is_space(*ptr))
	{
		if (*ptr == '\\')
			ptr++;
		else if (is_quote(*ptr))
			goto_next_quote(&ptr);
		else if (!ft_strncmp("$((", ptr, 3))
		{
			ptr++;
			goto_end_arithmetic(&ptr);
		}
		if (*ptr)
			ptr++;
	}
	*str = ptr;
}
