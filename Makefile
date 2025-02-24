# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mokon <mokon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 14:55:21 by mokon             #+#    #+#              #
#    Updated: 2025/02/24 15:57:40 by mokon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER 		= ft_printf.h
SRC 		= ft_printf.c printf_char.c printf_string.c printf_ptr.c \
				printf_nbr.c printf_hex.c printf_unbr.c
OBJS 		= $(SRC:.c=.o)

NAME 		= libftprintf.a
CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra
LIB_PATH 	= ./libft 
LIBFT 		= $(LIB_PATH)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIB_PATH) all 

%.o: %.c  $(HEADER)
	$(CC) -c $(CFLAGS) -I ./ $< -o $@  


fclean: clean
	make -C $(LIB_PATH) fclean
	rm -rf $(NAME)	

clean:
	rm -f $(OBJS)
	make -C $(LIB_PATH) clean

re: fclean all

.PHONY: all clean fclean re
