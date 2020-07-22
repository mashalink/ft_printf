# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlink <mlink@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 17:09:30 by mlink             #+#    #+#              #
#    Updated: 2020/07/22 19:58:50 by mlink            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
FLAGS = -Wall -Wextra -Werror -c
HEADER = ./includes

SRC_DIR = ./src/
SRC = ft_printf.c check.c save_param.c type_buox.c type_c.c\
		type_s.c type_di.c cheng_mod.c type_f.c type_p.c all.c\
		color.c print_buffer.c
SRCS=$(addprefix $(SRC_DIR), $(SRC))

LIB_SRC_DIR = ./libft/
LIB_SRC = ft_memset.c ft_strcat.c ft_strchr.c ft_strlen.c ft_strnew.c\
		ft_strcmp.c ft_strcpy.c ft_bzero.c ft_memalloc.c ft_strncpy.c\
		ft_join_del.c ft_strdup.c
LIB_SRCS=$(addprefix $(LIB_SRC_DIR), $(LIB_SRC))

OBJ = $(SRC:%.c=%.o) $(LIB_SRC:%.c=%.o)

RESET = \033[0m
YELLOW = \033[0;33m
GREEN = \033[0;32m
BOLD_BLUE = \033[1;34m

all: $(NAME)

$(NAME):
	@echo "$(GREEN)<<$(RESET)$(YELLOW)$(NAME) is compiling...$(GREEN)>>$(RESET)"
	@gcc $(FLAGS) $(SRCS) $(LIB_SRCS) -I $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)<<$(RESET)$(YELLOW)$(NAME) is ready to use$(GREEN)>>$(RESET)"

clean:
	@rm -f $(OBJ)
	@echo "   $(GREEN)<<$(RESET)$(YELLOW)all .o files are deleted$(GREEN)>>$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "    $(GREEN)<<$(RESET)$(YELLOW)$(NAME) deleted$(GREEN)>>$(RESET)"

re: fclean all

.PHONY: all clean fclean re
