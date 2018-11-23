# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/27 19:02:29 by aburdeni          #+#    #+#              #
#    Updated: 2018/11/19 18:03:26 by aburdeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

PRF_DIR = ./ft_printf/
PRF_SRC = ft_printf.c \
	handle_cs.c \
	handle_id.c \
	handle_oubxp.c \
	pr_color.c \
	pr_define_flags.c \
	pr_join.c \
	pr_utoa.c

SRC = ft_arraystrfree.c \
    ft_atoi.c \
	ft_atoi_base.c \
	ft_bzero.c \
	ft_getline.c \
	ft_is_descending_order.c \
	ft_is_ascending_order.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_itoa_base.c \
	ft_itoa.c \
	ft_lstadd.c \
	ft_lstaddend.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_max.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_min.c \
	ft_nbrlen.c \
	ft_nbrulen.c \
	ft_pow.c \
	ft_putchar_fd.c \
	ft_putchar.c \
	ft_putendl_fd.c \
	ft_putendl.c \
	ft_putnbr_fd.c \
	ft_putnbr.c \
	ft_putnstr.c \
	ft_putstr_fd.c \
	ft_putstr.c \
	ft_range.c \
	ft_shift.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strjoinfree.c \
	ft_strnjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_swap.c \
	ft_tolower.c \
	ft_toupper.c \
	$(addprefix $(PRF_DIR), $(PRF_SRC))
 
OBJ = $(SRC:.c=.o)

RESET = \033[0m
PURPLE = \033[2;35m
DIMCYAN = \033[2;36m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME).a $(OBJ)
	@echo "$(RESET)got $(DIMCYAN)$(NAME).a$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	
fclean: clean
	@$(RM) $(NAME).a
	@echo "$(DIMCYAN)$(NAME)/$(RESET) was fcleaned"

re: fclean all

.PHONY: all clean fclean re libft.a


# w/ spaceships

# all:
# 	@echo "release alien spaceships from $(DIMCYAN)$(NAME)/$(PURPLE)"
# 	@make $(NAME)

# $(NAME): $(OBJ)
# 	@echo "$(RESET)"
# 	@ar rc $(NAME).a $(OBJ)
# 	@echo "got $(DIMCYAN)$(NAME).a$(RESET)"

# %.o: %.c
# 	@$(CC) $(CFLAGS) -c $< -o $@
# 	@echo -n '  <@> '