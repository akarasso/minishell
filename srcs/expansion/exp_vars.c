#include "shell.h"

static char		*exp_vars_pos(char *str)
{
	while (*str)
	{
		if (*str == '\\')
			str++;
		else if (*str == '\'')
			goto_next_quote(&str);
		else if (*str == '$' && (ft_isalpha(*(str + 1))
			||  *(str + 1) == '?' || *(str + 1) == '{'))
			return (str);
		if (*str)
			str++;
	}
	return (0);
}

static void		goto_end_parent(char **s)
{
	int stack;

	stack = 0;
	while (**s)
	{
		if (**s == '{')
			stack++;
		if (**s == '}')
			stack--;
		if (!stack)
			break;
		(*s)++;
	}
}

static char		*exp_get_key(char *s)
{
	char *end;

	end = s;
	if (*s == '{')
		goto_end_parent(&end);
	else
	{
		if (ft_isdigit(*end) || *end == '?' || *end == '@' || *end == '*'
			|| *end == '#' || *end == '$' || *end == '-')
			return (ft_strsub(s, 0, end - s + 1));
		while (*end && (ft_isalpha(*end) || ft_isdigit(*end) || *end == '_'))
			end++;
	}
	if (*end)
		return (ft_strsub(s, 0, end - s + 1));
	else
		return (ft_strsub(s, 0, end - s));
}

void			exp_vars(char **str, t_cmd *cmd)
{
	char	*start;
	char	*pos;
	char	*key;
	char	*val;
	int		i;

	start = *str;
	i = 0;
	while ((pos = exp_vars_pos(&start[i])))
	{
		*pos = 0;
		i = pos - start + 1;
		if ((key = exp_get_key(&start[i])))
		{
			val = exp_get_var(key, cmd->shell->env);
			start = ft_3strjoinfree(start, val, &start[i + ft_strlen(key)], LEFT);
			i += ft_strlen(val) - 1;
			ft_strdel(&val);
		}
		ft_strdel(&key);
	}
	*str = start;
}
