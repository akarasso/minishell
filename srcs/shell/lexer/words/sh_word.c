#include "shell.h"

int		is_word(char *str)
{
	return (ft_isprint(*str) && !is_space(*str)) ? 1 : 0;
}

void	goto_end_word(char **str)
{
	char	*ptr;

	ptr = *str;
	while (*ptr && ft_strtab_strncmp_i(g_shell_op, ptr) == -1
		&& is_redirect(ptr) == -1 && !is_space(*ptr))
	{
		if (is_quote(*ptr))
			goto_next_quote(&ptr);
		ptr++;
	}
	*str = ptr;
}