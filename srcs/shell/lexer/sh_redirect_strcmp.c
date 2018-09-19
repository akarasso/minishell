#include "shell.h"

int		sh_redirect_strcmp(char *src, char *op, int *io_number)
{
	if (io_number)
		*io_number = (ft_isdigit(*src)) ? ft_atoi(src) : -1;
	while (ft_isdigit(*src))
		src++;
	return (ft_strncmp(src, op, ft_strlen(op)));
}
