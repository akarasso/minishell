#include "shell.h"

int			expansion_get_tild_expansion(char **str, t_cmd *cmd, char *home)
{
	char		*tmp;

	(void)cmd;
	if (!home)
		return (0);
	if ((*str)[0] == '~' && ((*str)[1] == '/' || !(*str)[1]))
	{
		tmp = *str;
		(*str) = ft_strjoinfree(home, &tmp[1], 0);
		free(tmp);
	}
	return (1);
}
