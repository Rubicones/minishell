# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 21:01:58 by ejafer            #+#    #+#              #
#   Updated: 2022/05/17 14:36:24 by                  ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

NAME	=	libminishell

NAMES	= lexer ft_split_quotes

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		= 	include/

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(NAMES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(NAMES)))
D_FILES		=	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(NAMES)))

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -O3
AR			=   ar rcs

MD			=	mkdir -p

all: ${NAME}


$(NAME): ${OBJ} Makefile 
			$(AR) libminishell ${OBJ}

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