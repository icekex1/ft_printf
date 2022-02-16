# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tom <tom@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 11:56:34 by tzeck             #+#    #+#              #
#    Updated: 2022/02/17 00:45:34 by tom              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

# directories
SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	libftprintf.h
LIBFT_DIR	=	libft/

# controll codes
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K

# source files
SRC_FILES = 	ft_flags.c ft_mfw_extensions.c ft_printf.c \
				ft_write_chars.c ft_write_hexa.c ft_write_d.c \
				ft_write_u.c ft_write_pointer.c ft_write_s.c 

# object files
OBJ_FILES	=	$(SRC_FILES:.c=.o)

# paths
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT		=	$(addprefix $(LIBFT_DIR), libft.a)

# libft linkers
LNK			=	-L $(LIBFT_DIR)

# all rule
all: $(NAME)
	@printf "\n"
	@echo "$(GREEN)   _____   __                          .__           __     _____  $(RESET)"
	@echo "$(GREEN) _/ ____\_/  |_        ______  _______ |__|  ____  _/  |_ _/ ____\ $(RESET)"
	@echo "$(GREEN) \   __\ \   __\       \____ \ \_  __ \|  | /    \ \   __\\   __\  $(RESET)"
	@echo "$(GREEN)  |  |    |  |         |  |_> > |  | \/|  ||   |  \ |  |   |  |    $(RESET)"
	@echo "$(GREEN)  |__|    |__|   ______|   __/  |__|   |__||___|  / |__|   |__|    $(RESET)"
	@echo "$(GREEN)                /_____/|__|                     \/                 $(RESET)"
	@printf "\n"

# compile ft_printf
$(NAME): $(OBJ) $(LIBFT)
	@ar -crs $(NAME) $(LIBFT_DIR)/libft.a $(OBJ)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

# compile objects
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CC) $(FLAGS) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

# compile libft
$(LIBFT):
	@echo "$(YELLOW)Compiling $(LIBFT_DIR) library...$(RESET)"
	@make -C $(LIBFT_DIR)

# clean rule
clean:
	@make -C $(LIBFT_DIR) clean
	@if [ -d "$(OBJ_DIR)" ]; then \
			rm -rf $(OBJ_DIR); \
			echo "$(BLUE)Deleting all objects from /ft_printf...$(RESET)"; else \
			echo "No objects to remove from /ft_printf."; \
	fi;

# fclean rule
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(BLUE)Deleting $(NAME) from /ft_printf...$(RESET)"; else \
		echo "No Executable to remove from /ft_printf."; \
	fi;

# re rule
re: fclean all

# added norm check
norm:
	@echo $(G)Checking Norminette...$(X)
	@norminette libft src include | grep Error | egrep --color '.*Error!|$$' || true
	@echo $(G)Done$(X)

# phony
.PHONY: all clean fclean re norm