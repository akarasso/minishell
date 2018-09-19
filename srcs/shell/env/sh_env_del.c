#include "shell.h"

int		sh_env_del(char **tabe, char *key)
{
	int	klen;

	klen = ft_strlen(key);
	while (*tabe)
	{
		if (!ft_strncmp(*tabe, key, klen) && (*tabe)[klen] == '=')
		{
			ft_strtab_del_one(tabe, 0);
			return (1);
		}
		tabe++;
	}
	return (0);
}
