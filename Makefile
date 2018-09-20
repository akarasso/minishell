CC	= gcc -g

CFLAGS	= -Wall -Werror -Wextra

NAME	= shell

HEADERS	= ./includes ./libft/includes

SOURCES	= ./srcs/global.c				./srcs/main.c				./srcs/arithmetic/math_ast_split.c		\
	./srcs/arithmetic/math_token.c		./srcs/arithmetic/math_simplify.c	./srcs/arithmetic/math_ast.c			\
	./srcs/arithmetic/math_destroy.c	./srcs/arithmetic/math_calc.c		./srcs/arithmetic/math_lexer.c			\
	./srcs/arithmetic/math_eval.c		./srcs/shell/exec/sh_exec.c		./srcs/shell/exec/sh_fd.c			\
	./srcs/shell/exec/sh_build_redir.c	./srcs/shell/exec/sh_exec_pipedcmd.c	./srcs/shell/exec/sh_exec_cmd.c			\
	./srcs/shell/exec/sh_bin_path.c		./srcs/shell/exec/sh_new_cmd.c		./srcs/shell/exec/sh_del_cmd.c			\
	./srcs/shell/ast/sh_ast_del.c		./srcs/shell/ast/sh_ast_split.c		./srcs/shell/ast/sh_ast_revsplit.c		\
	./srcs/shell/ast/sh_ast_construct.c	./srcs/shell/env/sh_env_init.c		./srcs/shell/env/sh_env_validkey.c		\
	./srcs/shell/env/sh_env_get.c		./srcs/shell/env/sh_env_set.c		./srcs/shell/env/sh_env_del.c			\
	./srcs/shell/lexer/sh_redirect_strcmp.c	./srcs/shell/lexer/sh_tokenize.c	./srcs/shell/lexer/sh_token_del.c		\
	./srcs/shell/lexer/sh_token_factory.c	./srcs/shell/lexer/sh_token_print.c	./srcs/shell/lexer/words/sh_operator.c		\
	./srcs/shell/lexer/words/sh_space.c	./srcs/shell/lexer/words/sh_quote.c	./srcs/shell/lexer/words/sh_word.c		\
	./srcs/shell/lexer/words/sh_redirect.c	./srcs/shell/io/sh_input.c		./srcs/shell/parser/sh_complete.c		\
	./srcs/shell/parser/sh_parser.c		./srcs/shell/parser/sh_heredoc.c	./srcs/shell/parser/sh_syntax.c			\
	./srcs/built_in/sh_unsetenv.c		./srcs/built_in/sh_unset.c		./srcs/built_in/sh_echo.c			\
	./srcs/built_in/sh_setenv.c		./srcs/built_in/sh_env.c		./srcs/built_in/sh_read_helper.c		\
	./srcs/built_in/sh_export.c		./srcs/built_in/built_in_cmp.c		./srcs/built_in/sh_read.c			\
	./srcs/built_in/built_in_new.c		./srcs/built_in/sh_exit.c		./srcs/built_in/sh_cd.c				\
	./srcs/expansion/exp_assign.c		./srcs/expansion/exp_vars.c		./srcs/expansion/exp_backslash.c		\
	./srcs/expansion/exp_substitute.c	./srcs/expansion/exp_get_var.c		./srcs/expansion/exp_tilde.c			\
	./srcs/expansion/sh_expansion.c		./srcs/expansion/exp_arithmetic.c

OBJ	= $(SOURCES:.c=.o)

HEADER_LIST	= $(addprefix -I,$(HEADERS))

all	: $(NAME)

makelib	:
	make -C libft/

cleanlib	:
	make clean -C libft/

fcleanlib	:
	make fclean -C libft/

%.o	: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(HEADER_LIST) -c -o $@ $<

$(NAME)	: $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(HEADER_LIST) -o $(NAME) $(OBJ) ./libft/libft.a

clean	: cleanlib
	rm -f $(OBJ)

re	: fcleanlib fclean all

fclean	: cleanlib clean
	rm -f $(NAME)
