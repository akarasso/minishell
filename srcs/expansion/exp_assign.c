#include "shell.h"

char	*exp_assign(t_varsexp *exp, char *key, char *val, char *word)
{
	(void)val;
	if (!sh_env_set(&exp->env->local, key, word, 0))
		ft_putendl("Failed to add vars to local");
	return (ft_strdup(word));
}

char	*exp_unhandle(t_varsexp *exp, char *key, char *val, char *word)
{
	(void)exp;
	(void)key;
	(void)val;
	(void)word;
	ft_putendl("shell expansion:: unhandle operator");
	return (0);
}
