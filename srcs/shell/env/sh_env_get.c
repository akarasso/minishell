#include "shell.h"

char	**sh_env_get_ref(char **tabe, char *key)
{
	int	klen;
	int	i;

	if (!tabe)
		return (0);
	klen = ft_strlen(key);
	i = 0;
	if (tabe)
	{
		while (tabe[i])
		{
			if (!ft_strncmp(tabe[i], key, klen) && tabe[i][klen] == '=')
				return (&tabe[i]);
			i++;
		}
	}
	return (0);
}

char	*sh_env_get(char **tabe, char *key)
{
	int	klen;

	if (!tabe || !key)
		return (0);
	klen = ft_strlen(key);
	while (*tabe)
	{
		if (!ft_strncmp(*tabe, key, klen) && (*tabe)[klen] == '=')
			return (ft_strchr(*tabe, '=') + 1);
		tabe++;
	}
	return (0);
}

char	*env_get_first(t_env *env, char *key)
{
	char	*ret;

	if ((ret = sh_env_get(env->public, key)))
		return (ret);
	else if ((ret = sh_env_get(env->private, key)))
		return (ret);
	else if ((ret = sh_env_get(env->local, key)))
		return (ret);
	return (0);
}
