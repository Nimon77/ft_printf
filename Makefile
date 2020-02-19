# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsimon <nsimon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/29 17:07:11 by nsimon            #+#    #+#              #
#    Updated: 2020/02/19 00:56:36 by nsimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC_PATH = ./includes/

SRC_PATH = ./srcs/

SRC_NAME =	ft_printf.c					\
			ft_printf_simple.c			\
			ft_printf_uint.c			\
			ft_printf_pointer.c			\
			ft_hexa_converter.c			\
			ft_flags.c					\
			ft_utils.c

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH = ./objs/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

LBPATH = ./libft/

LDFLAGS = -L$(LBPATH)

LIB = $(LBPATH)libft.a

CC = gcc $(CFLAGS)

CFLAGS = -Wall -Wextra -Werror

TEMP = .temp.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LBPATH)
	@echo "\033[34mCreation of $(NAME) ...\033[0m"
	@cp $(LIB) $(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32m$(NAME) created\n\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I$(INC_PATH) -o $@ -c $<

clean:
	@make clean -C $(LBPATH)
	@echo "\033[33mRemoval of .o files of $(NAME) ...\033[0m"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[31mFiles .o deleted\n\033[0m"

fclean: clean
	@make fclean -C $(LBPATH)
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -f $(NAME) $(TEMP)
	@echo "\033[31mBinary $(NAME) deleted\n\033[0m"

re: fclean all

git:
	@git add .
	@git commit -m "$(NAME)"
	@git push

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY: all, clean, fclean, re