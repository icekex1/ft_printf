# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tom <tom@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 15:36:01 by tzeck             #+#    #+#              #
#    Updated: 2022/02/16 16:22:51 by tom              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

# source files
SRC_FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_striteri.c

# directories
SRC_DIR		=	src/
OBJ_DIR		=	obj/

# controll codes
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K

# object files
OBJ_FILES	=	$(SRC_FILES:.c=.o)

# paths
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

# all rule
all: $(NAME)
	@printf "\n"
	@echo "$(GREEN)                 $(RESET)"
	@echo "$(GREEN) _ _ _   ___ _   $(RESET)"
	@echo "$(GREEN)| |_| |_|  _| |_ $(RESET)"
	@echo "$(GREEN)| | | . |  _|  _|$(RESET)"
	@echo "$(GREEN)|_|_|___|_| |_|  $(RESET)"
	@echo "$(GREEN)                 $(RESET)"
	@printf "\n"

# compiling it to .a file
$(NAME): $(OBJ)
	@ar -crs $(NAME) $(OBJ)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

# compiling objects
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I libft.h -c $< -o $@
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

# clean rule
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
			rm -rf $(OBJ_DIR); \
			echo "$(BLUE)Deleting all objects from /libft...$(RESET)"; \
	fi;

# fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(BLUE)Deleting $(NAME) from /libft...$(RESET)"; else\
		echo "No $(NAME) to remove from /libft."; \
	fi;

# re rule
re : fclean all

# phony
.PHONY: all clean fclean re