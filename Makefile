# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 15:36:01 by tzeck             #+#    #+#              #
#    Updated: 2021/08/05 18:13:53 by tzeck            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c

OBJ = $(SRCS:.c=.o)

#BONUS = ft_lst*.c

#BONUS_OBJ = $(BONUS:.c=.o)

INCLUDES=./

all: $(NAME)

$(NAME): $(SRCS) ft_printf.h
	gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS) libft.h
	gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(BONUS)
	ar rcs $(NAME) $(BONUS_OBJ)

.PHONY: all clean fclean re