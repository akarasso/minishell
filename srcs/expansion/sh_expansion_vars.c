#include "shell.h"

t_varsexp_rules	g_varsexp_rules[12] ={
	{":-", sh_exp_sub_param, sh_exp_sub_word, sh_exp_sub_word},
	{"-", sh_exp_sub_param, sh_exp_sub_null, sh_exp_sub_word},
	{":=", sh_exp_sub_param, sh_exp_assign, sh_exp_assign},
	{"=", sh_exp_sub_param, sh_exp_sub_null, sh_exp_assign},
	{":?", sh_exp_sub_param, sh_exp_sub_error, sh_exp_sub_error},
	{"?", sh_exp_sub_param, sh_exp_sub_null, sh_exp_sub_error},
	{":+", sh_exp_sub_word, sh_exp_sub_null, sh_exp_sub_null},
	{"+", sh_exp_sub_word, sh_exp_sub_word, sh_exp_sub_null},
	{"%%", sh_exp_unhandle, sh_exp_unhandle, sh_exp_unhandle},
	{"%", sh_exp_unhandle, sh_exp_unhandle, sh_exp_unhandle},
	{"##", sh_exp_unhandle, sh_exp_unhandle, sh_exp_unhandle},
	{"#", sh_exp_unhandle, sh_exp_unhandle, sh_exp_unhandle}
};

static t_varsexp_rules	*get_rules(char *s)
{
	int i;

	i = 0;
	while (i < 12)
	{
		if (ft_strstr(s, g_varsexp_rules[i].op))
			return &g_varsexp_rules[i];
		i++;
	}
	return (0);
}

static void				apply_rule(t_varsexp *vexp)
{
	char	*word;
	char	*val;
	char	*pos;

	pos = ft_strstr(vexp->str, vexp->rule->op);
	*pos = 0;
	word = &pos[ft_strlen(vexp->rule->op)];
	val = env_get_first(vexp->env, vexp->str);
	if (!val)
		vexp->res = vexp->rule->unset(vexp, vexp->str, val, word);
	else if (val && !*val)
		vexp->res = vexp->rule->null(vexp, vexp->str, val, word);
	else
		vexp->res = vexp->rule->set(vexp, vexp->str, val, word);
}

static	char			*exp_res(t_varsexp *vexp)
{
	char	*tmp;

	if ((vexp->rule = get_rules(vexp->str)))
		apply_rule(vexp);
	else
	{
		tmp = env_get_first(vexp->env, vexp->str);
		vexp->res = (tmp) ? ft_strdup(tmp) : ft_strdup("");
	}
	if (vexp->res && vexp->format == NBR_FORMAT)
	{
		tmp = ft_itoa(ft_strlen(vexp->res));
		free(vexp->res);
		vexp->res = tmp;
	}
	return (vexp->res);
}

char					*sh_expansion_var(char *str, t_env *env)
{
	t_varsexp	vexp;

	if (*str == '#') {
		str++;
		vexp.format = NBR_FORMAT;
	}
	else
		vexp.format = STR_FORMAT;
	vexp.env = env;
	vexp.str = str;
	vexp.res = 0;
	return (exp_res(&vexp));
}
