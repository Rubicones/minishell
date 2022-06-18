# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 21:01:58 by ejafer            #+#    #+#              #
#    Updated: 2022/06/18 11:51:39 by ejafer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

NAMES	=	minishell\
			spliter/split_line	spliter/process_separator	spliter/process_quotes\
			spliter/split_data	spliter/process_word\
			parser/parse		parser/parser_data			parser/token\
			parser/set_command	parser/set_pipe				parser/set_redir\
			parser/is_redir		parser/is_pipe\
			executor/executor	executor/command			executor/open_redir\
			executor/findpath	executor/duplicate_fd\
			error/throw_error	builtins/builtins	builtins/mini_echo\
			builtins/mini_cd	builtins/mini_env	builtins/mini_pwd\

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		= 	include/

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(NAMES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(NAMES)))
D_FILES		=	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(NAMES)))

CC			=	cc
CFLAGS		=	-O3 -g
AR			=   ar rcs

MD			=	mkdir -p

all: ${NAME}

libft.a:
		$(MAKE) -C src/libft

$(NAME): ${OBJ} Makefile | libft.a
			$(CC) $(CFLAGS) $(OBJ) -L src/libft/ -lft -lreadline -o ${NAME}

$(OBJ_DIR):
			${MD} $(OBJ_DIR)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -I$(INC_DIR) -o $@ -MD

include $(wildcard $(D_FILES))

clean:
			rm -f ${OBJ} ${OBJ_B} $(D_FILES)

fclean:	clean
			rm -f ${NAME}

re:	fclean all

.PHONY: re fclean clean bonus all