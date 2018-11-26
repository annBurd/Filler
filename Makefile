# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/27 18:17:42 by aburdeni          #+#    #+#              #
#    Updated: 2018/11/23 18:49:31 by aburdeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler
LOGIN = aburdeni.$(NAME)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

HEADER = $(wildcard $(INC_DIR)*.h)

SRC = filler.c \
    search_place.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

RESET = \033[0m
PURPLE = \033[2;35m
DIMCYAN = \033[2;36m

all:
	@mkdir -p $(OBJ_DIR)
	@echo "$(RESET)start compilation"
	@make -C $(LIBFT_DIR)
	@echo "release alien spaceships from $(DIMCYAN)$(NAME)/$(PURPLE)"
	@make $(LOGIN)

$(LOGIN): $(OBJ)
	@$(CC) $(CFLAGS) -o $(LOGIN) $(OBJ) $(LIBFT)
	@echo "$(RESET)"
	@echo "got $(DIMCYAN)$(LOGIN)$(RESET) binary"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n '  <@>'

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(INC_DIR)*.h.gch
	@make -C $(LIBFT_DIR) clean
	
fclean:	
	@make clean
	@rm -rf $(LOGIN)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(DIMCYAN)$(NAME)/$(RESET) was fcleaned"

re: fclean all

.PHONY: all clean fclean re aburdeni.filler
