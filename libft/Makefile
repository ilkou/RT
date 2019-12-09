# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oouklich <ouklichoussama@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/19 18:21:45 by oouklich          #+#    #+#              #
#    Updated: 2019/09/28 23:01:56 by oouklich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_putchar.c ft_striteri.c ft_striter.c
SRC += ft_atoi.c ft_putchar_fd.c ft_strjoin.c
SRC += ft_bzero.c ft_putendl.c ft_strlcat.c
SRC += ft_countword.c ft_putendl_fd.c ft_strlen.c
SRC += ft_isalnum.c ft_putnbr.c ft_strlowcase.c
SRC += ft_isalpha.c ft_putnbr_fd.c ft_strmap.c
SRC += ft_isascii.c ft_putstr.c ft_strmapi.c
SRC += ft_isdigit.c ft_putstr_fd.c ft_strncat.c
SRC += ft_isprint.c ft_sort_params.c ft_strncmp.c
SRC += ft_itoa.c ft_str_is_alpha.c ft_strncpy.c
SRC += ft_lstadd.c ft_str_is_lowercase.c ft_strnequ.c
SRC += ft_lstdel.c ft_str_is_numeric.c ft_strnew.c
SRC += ft_lstdelone.c ft_str_is_printable.c ft_strnstr.c
SRC += ft_lstiter.c ft_str_is_uppercase.c ft_strrchr.c
SRC += ft_lstmap.c ft_strcapitalize.c ft_strsplit.c
SRC += ft_lstnew.c ft_strcat.c ft_strstr.c
SRC += ft_memalloc.c ft_strchr.c ft_strsub.c
SRC += ft_memccpy.c ft_strclr.c ft_strtrim.c
SRC += ft_memchr.c ft_strcmp.c ft_strupcase.c
SRC += ft_memcmp.c ft_strcpy.c ft_tolower.c
SRC += ft_memcpy.c ft_strdel.c ft_toupper.c
SRC += ft_memdel.c ft_strdup.c get_next_line.c
SRC += ft_memmove.c ft_strequ.c ft_memset.c
SRC += ft_dtoa.c ft_mystrjoin.c ft_rand48.c
SRC += get_full_text.c ft_atod.c
SRC += ft_free_twodim.c ft_twodimlen.c
SRC += ft_swap_d.c ft_swap_i.c
SRC += ft_mind3.c ft_maxd3.c

OBJ = $(SRC:.c=.o)

OK_COLOR=\x1b[102;01m
GREEN_COLOR=\x1b[32;01m
NO_COLOR=\x1b[0m
ERROR_COLOR=\x1b[31;01m
WARN_COLOR=\x1b[33;01m
BUILD_PRINT = $(GREEN_COLOR)libft.a successfully compiles$(NO_COLOR)
OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)
KO_STRING=$(ERROR_COLOR)[KO]$(NO_COLOR)
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $^
	@ranlib $(NAME)
	@echo "$(BUILD_PRINT)"

COMPILE_OBJECT = gcc $(CFLAGS) -o $@ -c $< -I . 2>/dev/null && echo "$(OK_STRING)" || echo "$(KO_STRING)" 

%.o: %.c
	@echo "Compiling $< ==> $@ `$(COMPILE_OBJECT)`"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
