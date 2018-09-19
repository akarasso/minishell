#include "shell.h"

t_func	*built_in_new(char *key, int (*func)(t_cmd*))
{
	t_func	*new;

	if (!(new = (t_func*)malloc(sizeof(*new))))
		return (0);
	if (!(new->name = ft_strdup(key)))
	{
		free(new);
		return (0);
	}
	new->func = func;
	return (new);
}
