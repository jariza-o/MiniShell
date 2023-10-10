# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/17 12:59:03 by jariza-o          #+#    #+#              #
#    Updated: 2023/10/10 19:50:20 by jjaen-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Libreries
LIBFT =		libft/libft.a

#Flags
INC		= -I /Users/$(USER)/.brew/opt/readline/include

LFLAGS	= -lreadline -L /Users/$(USER)/.brew/opt/readline/lib
CFLAGS =	-Wall -Werror -Wextra
COMPILE =	-g

# Minishell
NAME =		Minishell
SRC =		src/main.c \
			src/built-ins/echo/echo.c src/built-ins/cd/cd.c \
			src/built-ins/pwd/pwd.c src/built-ins/env/env.c \
			src/built-ins/export/export.c src/built-ins/unset/unset.c \
			src/built-ins/exit/exit.c \
			src/parser/ft_mini_split.c src/parser/tokens/init_token.c src/parser/tokens/token.c src/parser/tokens/tokens_to_str.c \
			src/parser/expand/expand_env.c src/parser/expand/expand.c src/parser/expand/expand_quotes.c \
			src/errors/special_caracters/quotes.c src/errors/special_caracters/slash_semicolon.c  src/errors/redirections/redirections.c src/errors/errors.c \
			src/otherfts/system-cmds.c src/otherfts/clean.c src/otherfts/pipes.c\
			src/signals/signals.c \

OBJT =		$(SRC:.c=.o)

# Colors
GREEN		= \033[0;32m
YELLOW =	\033[0;93m
FYELLOW =	\033[38;5;154m
BLUE =		\033[0;96m
PURPLE =	\033[0;95m
PINK =		\033[0;91m
RED =		\033[0;31m
END =		\033[0m

.c.o:
			gcc ${CFLAGS} -I ~/.brew/opt/readline/include -I /usr/local/opt/readline/include -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME): ${OBJT}
			@if [ ! -e $(LIBFT) ]; then \
				echo "$(YELLOW)Compiling Libft.$(END)"; \
				make -s -C libft; \
				make clean -s -C libft; \
				echo "$(GREEN)Libft Compiled.$(END)"; \
			else \
				echo "$(GREEN)Libft is already compiled.$(END)"; \
			fi
			@echo "$(YELLOW)Compiling Minishell.$(END)"
			@gcc ${CFLAGS} ${INC} ${COMPILE} ${LIBFT} ${OBJT} -o ${NAME} ${LFLAGS}
			@echo "$(GREEN)Minishell Compiled.$(END)"

clean:
			@rm -f ${OBJT}
			@echo "$(RED)Compiled objects have been removed.$(END)"

fclean:		clean
			@rm -f ${NAME}
			@make fclean -s -C libft
			@echo "$(RED)Executables objects have been removed.$(END)"

re:			fclean all

norminette:
		@echo "$(YELLOW)Norminette libft.$(END)"
		@norminette ./libft
		@echo "$(YELLOW)Norminette minishell.$(END)"
		@norminette ./src

.PHONY: all clean fclean re norminette