#include "shell.h"

void	exp_backslash(char **str)
{
	char	*s;

	s = *str;
	while (*s)
	{
		if (*s == '\\')
			ft_strrmvchr(s);
		s++;
	}
}
