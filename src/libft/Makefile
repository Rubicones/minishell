# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 20:15:28 by ejafer            #+#    #+#              #
#    Updated: 2022/06/07 14:46:05 by ejafer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

HDR		= 	libft.h

NAMES	=	ft_atoi			ft_bzero		ft_calloc\
			ft_isalnum		ft_isalpha		ft_isascii\
			ft_isdigit		ft_isprint		ft_itoa\
			ft_memchr		ft_memcmp		ft_memcpy\
			ft_memmove		ft_memset		ft_putchar_fd\
			ft_putendl_fd	ft_putnbr_fd	ft_putstr_fd\
			ft_split		ft_strchr		ft_strdup\
			ft_striteri		ft_strjoin		ft_strlcat\
			ft_strlcpy		ft_strlen		ft_strmapi\
			ft_strncmp		ft_strnstr		ft_nbrlen\
			ft_strrchr		ft_strtrim		ft_substr\
			ft_tolower		ft_toupper		ft_memccpy\
			ft_lstnew		ft_lstadd_front	ft_lstsize\
			ft_lstlast		ft_lstadd_back	ft_lstclear\
			ft_lstiter		ft_lstmap		ft_lstdelone\
			ft_printf 		ft_format_str	ft_format_int\
			ft_format_hex	ft_add_width	ft_add_precision_nbr\
			ft_unbr_to_base get_next_line	ft_arrnew\
			ft_arrlen		ft_arr_addback  ft_strnew\
			ft_str_addletter

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

$(NAME): ${OBJ}
			$(AR) ${NAME} ${OBJ}

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
