# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 11:20:25 by cpieri            #+#    #+#              #
#    Updated: 2020/10/08 10:29:59 by cpieri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_nm

# ***************** #
#		Flags		#
# ***************** #
CC		=	gcc
override CFLAGS	+=	-Wall -Wextra -Werror $(ERROR)
CPPFLAGS=	-Iincludes
FLAGSFT	=	-L./../../libft -lft
ERROR	=	-g3 -flto -fsanitize=address -fno-omit-frame-pointer

# ***************** #
#		Sources		#
# ***************** #
DEPS =		Makefile			\
			includes/ft_nm.h	\
			../../libft/libft.a

SRC_NAME= 	main.c		\
            macho_32.c	\
            macho_64.c	\
            fat.c		\
            archive.c	\
            utils.c		\
            index.c		\
            sort_print.c

# ***************** #
#		Paths		#
# ***************** #
SRC_PATH=	srcs
OBJ_PATH=	obj

OBJ_NAME=	$(SRC_NAME:.c=.o)

SRC		=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ		=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

# ***************** #
#		Colors		#
# ***************** #
NONE	=	\033[0m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
MAGENTA	=	\033[35m
CYAN	=	\033[36m

# ***************** #
#		Rules		#
# ***************** #
all:		$(NAME)

$(NAME):	echo $(OBJ)
			@$(CC) $(CFLAGS) $(FLAGSFT) -o $(NAME) $(OBJ) $(CPPFLAGS)
			@echo "$(GREEN)$(NAME) ready!$(NONE)"

echo:
			@echo "Getting $(NAME) ready"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(DEPS)
			@mkdir -p $(dir $@) 2> /dev/null || true
			@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
			@echo "$(YELLOW)Cleaning $(NAME)...$(NONE)"
			@/bin/rm -f $(OBJ)
			@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean:		clean

re:			fclean all

.PHONY:	all clean fclean re echo