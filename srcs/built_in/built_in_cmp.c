#include "shell.h"

int		built_in_cmp(void *data, void *data2)
{
	return (ft_strcmp(((t_func*)data)->name, ((t_func*)data2)->name));
}

int		built_in_find(void *data, void *data2)
{
	return (ft_strcmp(((t_func*)data)->name, (char*)data2));
}
