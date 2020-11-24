# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 18:38:31 by tmilon            #+#    #+#              #
#    Updated: 2020/04/27 14:19:05 by cpieri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	gcc

ERROR	=	-g3 -flto -fsanitize=address -fno-omit-frame-pointer

override CFLAGS	+=	-Wall -Wextra -Werror #$(ERROR)

INCS	=	libft.h

HEADERS	=	./libft.h

SRC_PATH=	srcs

OBJ_PATH=	obj

CPPFLAG	=	-Iinclude

DEPS =		Makefile					\
			include/libft.h				\
			include/get_next_line.h

SRCS = 		ft_atoi.c					\
 			ft_bzero.c					\
			ft_ishexa_color.c			\
			ft_ishexa.c			\
			ft_isspace.c				\
  			ft_isalnum.c				\
	 		ft_isalpha.c				\
	  		ft_isascii.c				\
			ft_isdigit.c 				\
			ft_isprint.c				\
			ft_itoa.c					\
			ft_memput.c					\
			ft_memalloc.c				\
	 		ft_memccpy.c				\
	  		ft_memchr.c					\
		 	ft_memcmp.c 				\
			ft_memcpy.c					\
			ft_memdel.c					\
			ft_memmove.c				\
			ft_memset.c					\
			ft_memdup.c					\
			ft_memjoin.c				\
			ft_putchar.c 				\
			ft_putchar_fd.c				\
			ft_putendl.c				\
			ft_putendl_fd.c				\
			ft_putnbr.c					\
			ft_puthexa.c				\
			ft_put64hexa.c				\
			ft_put32hexa.c				\
			ft_putnbr_fd.c				\
			ft_putstr.c					\
			ft_putstr_fd.c				\
			ft_hex64_to_char.c			\
			ft_hex32_to_char.c			\
			ft_strcat.c					\
			ft_strchr.c					\
			ft_strclr.c					\
			ft_strcmp.c 				\
			ft_strcpy.c					\
			ft_strdel.c					\
			ft_strdup.c					\
			ft_strequ.c					\
			ft_striter.c				\
			ft_striteri.c				\
			ft_strjoin.c				\
			ft_strlcat.c				\
			ft_strlen.c					\
			ft_strmap.c					\
			ft_strmapi.c				\
			ft_strncat.c				\
			ft_strncmp.c				\
			ft_strncpy.c				\
			ft_strnequ.c				\
			ft_strnew.c 				\
			ft_strnstr.c				\
			ft_strrchr.c				\
			ft_strsplit.c				\
			ft_strstr.c					\
			ft_strsub.c					\
			ft_strtrim.c				\
			ft_tolower.c				\
			ft_toupper.c				\
			ft_lstadd.c					\
			ft_lstdel.c					\
			ft_lstdelone.c				\
			ft_lstnew.c					\
			ft_lstiter.c				\
			ft_lstmap.c					\
			ftb_trimtodigit.c			\
			ftb_intlen.c				\
			ftb_lstpush.c				\
			ftb_clamp.c 				\
			ftb_rand.c					\
			ftb_adjustmagn.c			\
			ftb_pow.c					\
			ftb_backwardmemcpy.c		\
			ftb_lstlastpop.c			\
			debug_print_list.c			\
			ft_sqrt.c					\
			get_next_line.c				\
			ft_abort.c					\
			ftb_hex2int.c				\
			hex2uint64t.c				\
			ftb_free_multiarray.c		\
			ftb_find_closest_offset.c	\
			ftb_abs.c					\
			ft_countstrtab.c			\
			ft_atof.c					\
			ft_atol.c					\
			ft_strbits.c				\
			ft_membits.c				\
			ft_membit_pos.c				\
			ft_left_shift.c				\
			ft_left_rotate.c			\
			ft_right_rotate.c			\
			ft_swap_uint32t.c			\
			ft_swap_uint64t.c			\
			ft_putbits.c				\
			ft_hexdump.c

OBJS	=	$(SRCS:.c=.o)

SRC		=	$(addprefix $(SRC_PATH)/,$(SRCS) )

OBJ		=	$(addprefix $(OBJ_PATH)/,$(OBJS) )

.PHONY: all clean fclean re echo

all:		echo $(NAME)

$(NAME): 	$(OBJ)
				@ar rc $(NAME) $(OBJ)
				@ranlib $(NAME)

echo:
				@echo -n Getting libft ready

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(DEPS)
				@mkdir $(OBJ_PATH) 2> /dev/null || true
				@$(CC) $(CFLAGS) $(CPPFLAG) -o $@ -c $<
				@echo -n .

clean:
				@/bin/rm -f $(OBJ)
				@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean:		clean
				@/bin/rm -f $(NAME)

re:			fclean all
