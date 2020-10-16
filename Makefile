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

NAME	=	template

CC		=	gcc

ERROR	=	-g3 -flto -fsanitize=address -fno-omit-frame-pointer

override CFLAGS	+=	-Wall -Wextra -Werror

CPPFLAGS=	-Iincludes

SRC_PATH=	srcs

OBJ_PATH=	obj

DEPS =		Makefile						\
			includes/template.h

SRC_NAME= 	main.c

OBJ_NAME=	$(SRC_NAME:.c=.o)

SRC		=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ		=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

NONE	=	\033[0m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
MAGENTA	=	\033[35m
CYAN	=	\033[36m

.PHONY:	all clean fclean re echo

all:		$(NAME)

$(NAME):	echo $(OBJ)
			@$(CC) $(CFLAGS) $(FLAGSFT) -o $(NAME) $(OBJ) $(CPPFLAGS)
			@echo "\n$(GREEN)$(NAME) ready!$(NONE)"

echo:
			@ echo -n Getting $(NAME) ready

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(DEPS)
			@mkdir $(dir $@) 2> /dev/null || true
			@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
			@echo -n .

clean:
			@echo "$(YELLOW)Cleaning...$(NONE)"
			@/bin/rm -f $(OBJ)
			@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean:		clean
			@/bin/rm -f $(NAME)
			@echo "$(RED)$(NAME) deleted !$(NONE)"

re:			fclean all
