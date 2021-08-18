# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 20:53:58 by rschleic          #+#    #+#              #
#    Updated: 2021/08/18 11:36:45 by rschleic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror -c
SRC = ft_fun_with_flags.c ft_mfw_extensions.c ft_printf.c \
ft_write_chars.c ft_write_hexa.c ft_write_i_d.c ft_write_u.c ft_write_pointer.c ft_write_s.c 

all: $(NAME)

$(NAME): *.c
	Make -C ./libft
	cp ./libft/libft.a $(NAME)
	${COMPILER} $(CFLAGS) $(SRC)
	ar rc $(NAME) *.o

libft:
	cd /libft make
	ar rc $(NAME) *.o

clean:
	rm -f ./libft/*.o
	rm -f *.o

fclean: clean
	rm -f ./libft/libft.a
	rm -f $(NAME)
re: fclean all

bonus: all