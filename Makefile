CC	= gcc

CFLAGS	= #-Wall -Werror -Wextra

NAME	= minishell

HEADERS	= ./includes ./libft/includes

SOURCES	= ./srcs/env.c		./srcs/env_to_lst.c	./srcs/main.c			\
	./srcs/parse.c		

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

