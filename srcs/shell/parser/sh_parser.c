#include "shell.h"

int		sh_parser(t_shell *sh)
{
	while (parser_check_quote(sh) || parser_check_operator(sh))
	{}
	if (!parser_syntax(sh))
		return (0);
	if (!sh_heredoc(sh))
		return (0);
	return (1);
}