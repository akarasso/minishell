#include "shell.h"

char	*sh_exp_assign(t_varsexp *exp, char *key, char *val, char *word)
{
	(void)val;
	if (!sh_env_set(&exp->env->local, key, word, 0))
	{
		printf("Failed to add vars to local\n");
	}
	return (ft_strdup(word));
}

char	*sh_exp_unhandle(t_varsexp *exp, char *key, char *val, char *word)
{
	(void)exp;
	(void)key;
	(void)val;
	(void)word;
	ft_putendl("shell expansion:: unhandle operator");
	return (0);
}
