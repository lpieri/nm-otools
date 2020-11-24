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

NM		= ft_nm
OTOOL	= ft_otool

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
all:		LFT $(NAME)

$(NAME):
			@make -C ./srcs/$(OTOOL)
			@make -C ./srcs/$(NM)
			@mv ./srcs/$(OTOOL)/$(OTOOL) .
			@mv ./srcs/$(NM)/$(NM) .
			@echo "$(GREEN)It's ready!$(NONE)"

clean:
			@echo "$(YELLOW)Cleaning...$(NONE)"
			@make clean -C ./libft/
			@make clean -C ./srcs/$(OTOOL)
			@make clean -C ./srcs/$(NM)

fclean:		clean
			@make fclean -C ./libft/
			@rm -rf $(OTOOL)
			@rm -rf $(NM)

re:			fclean all

LFT:
		@make -C ./libft/;
		@echo "\n$(GREEN)Libft ready!$(NONE)";

.PHONY:	all clean fclean re echo LFT