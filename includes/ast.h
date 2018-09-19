#ifndef AST_H
# define AST_H

void	sh_ast_construct(t_shell *sh);
int		sh_ast_revsplit(t_ast_node *ast, int (*f)(void*));
int		sh_ast_split(t_ast_node *ast, int(*func)(void*));
void	sh_ast_del(t_ast_node **ast);

#endif