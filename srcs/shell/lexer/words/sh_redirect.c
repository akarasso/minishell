#include "shell.h"

int		is_redirect(char *str)
{
	int i;
	int last;

	i = 0;
	last = -1;
	while (g_shell_redirect[i])
	{
		if (!sh_redirect_strcmp(str, g_shell_redirect[i], 0))
			last = i;
		i++;
	}
	return (last);
}
