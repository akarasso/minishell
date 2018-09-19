#ifndef PARSER_H
# define PARSER_H

int		sh_parser(t_shell *sh);
int		parser_check_quote(t_shell *sh);
int		parser_check_operator(t_shell *sh);
int		parser_syntax(t_shell *sh);
int		sh_heredoc(t_shell *sh);

#endif
