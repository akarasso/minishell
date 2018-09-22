/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 11:12:04 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/22 11:22:37 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_MATH_H
# define SHELL_MATH_H

# define STR_FORMAT 0
# define NBR_FORMAT 1

# define MATH_NUMBER 1
# define MATH_PARENTHESE 2
# define MATH_OPERATOR 3

# define MATH_MALLOC_ERROR 1
# define MATH_SUBCALC_ERROR 2
# define MATH_DIVIDE_ERROR 3

typedef struct	s_math_eval
{
	t_dlst		*lexer;
	t_ast_node	*ast;
	int			*result;
	int			error;
}				t_meval;

int				math_eval(char *s, int *res);
void			math_destroy(t_meval *ptr);
void			math_destroy_tkn(t_dlst_elem *data);

int				math_calc(t_meval *math_eval, t_ast_node *node);

t_ast_node		*math_ast(t_dlst	*lexer);

void			math_ast_split_tree(t_ast_node *ast, int(*func)(void *data));

int				math_lexer(t_meval *math_eval, char *str);

int				math_push_number(t_dlst	*lexer, char **str);
int				math_push_parenthese(t_dlst	*lexer, char **str);
int				math_push_op(t_dlst	*lexer, char **str);
int				math_is_op(char c);
int				math_do_op(t_ast_node *node);
void			math_simplify(char *s);
int				math_push_preparenthese(t_dlst	*lexer, char **str);

#endif
