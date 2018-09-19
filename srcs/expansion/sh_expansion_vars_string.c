#include "shell.h"

static int	exp_len_key(char *str)
{
	int len;

	len = 1;
	if (ft_isdigit(*str) || *str == '?' || *str == '@' || *str == '*'
		|| *str == '#' || *str == '$' || *str == '-')
		return (len);
	while (*str && (ft_isalpha(*str) || ft_isdigit(*str) || *str == '_'))
	{
		str++;
		len++;
	}
	return (len - 1);
}


static char		*exp_vars_pos(char *str)
{
	while (*str)
	{
		if (*str == '\\')
			str++;
		else if (*str == '\'')
			goto_next_quote(&str);
		else if (*str == '$' && (ft_isalpha(*(str + 1)) ||  *(str + 1) == '?'))
			return (str);
		if (*str)
			str++;
	}
	return (0);
}

static char		*exp_vars_key(char *str)
{
	int		klen;
	char	*key;

	klen = exp_len_key(str);
	key = ft_strndup(str, klen);
	return (key);
}

void			sh_expansion_vars_string(char **str, t_cmd *cmd)
{
	char	*pos;
	char	*key;
	char	*val;

	while ((pos = exp_vars_pos(*str)))
	{
		if (!(key = exp_vars_key(pos + 1)))
			return ;
		*pos = 0;
		val = env_get_first(cmd->shell->env, key);
		*str = ft_3strjoinfree(*str, val, pos + 1 + ft_strlen(key), LEFT);
		ft_strdel(&key);
	}
}
