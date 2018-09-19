#ifndef LEXER_H
# define LEXER_H

int			sh_redirect_strcmp(char *src, char *op, int *io_number);
void		sh_tokenize(t_shell *sh);
void		sh_lexer_print(t_shell *sh);
void		sh_token_del(void *data);

/*
** Word
*/

int			is_space(char chr);

int			is_redirect(char *str);

int			is_word(char *str);
void		goto_end_word(char **str);

int			is_quote(char c);
void		goto_next_quote(char **str);
int			quote_str_valid(char *str);

int			sh_tkn_is_operator(void *data);
int			is_terminator(void *data);
int			is_logical(void *data);
int			is_pipe(void *data);

/*
** Token
*/

void		sh_newtkn_op(int value, char **cmd, t_shell *sh);
void		sh_newtkn_redirect(int value, char **cmd, t_shell *sh);
void		sh_newtkn_word(char **cmd, t_shell *sh);

#endif
