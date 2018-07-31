#include "libft.h"
#include "minishell.h"

int main(int argc, char const **argv)
{
	char *line;

	line = 0;
	while (get_next_line(0, line) > 0)
	{
		ft_putstr("$>");
		ft_strdel(&line);
	}
	return 0;
}