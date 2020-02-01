# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 11:09:20 by hlourtie          #+#    #+#              #
#    Updated: 2019/11/14 17:38:52 by hlourtie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC		:= gcc
C_FLAGS	:= -Wall -Wextra -Werror
C_FILES:= src/fct_util.c\
					src/imprim_char.c\
					src/imprim_d.c\
					src/imprim_hex.c\
					src/imprim_perc.c\
					src/printf_util.c\
					src/util_hex.c\
					src/ft_printf.c
C_FILESLFT := inc/libft/ft_atoi.o\
					inc/libft/ft_itoa.o\
					inc/libft/ft_memset.o\
					inc/libft/ft_putchar_fd.o\
					inc/libft/ft_strjoin_free_bonus.o\
					inc/libft/ft_strlen.o\
					inc/libft/ft_putstr_fd.o\
					inc/libft/ft_substr.o\
					inc/libft/ft_isdigit.o

INC := inc/ft_printf.h
LIBFT_PATH =  ./inc/libft


SOURCES	:= $(C_FILES)
INCUDES	:= $(addprefix -I , $(INC))
OBJECTS	:= $(patsubst %.c, %.o, $(C_FILES))

all: $(NAME)

%.o : %.c
	@$(CC) $(C_FLAGS) -c $< -o $@ $(INCUDES)

$(NAME) : $(OBJECTS)
	@$(MAKE) -C ./inc/libft/ all
	@ar -rc $@ $(OBJECTS) $(C_FILESLFT)
	@ranlib $@
	@echo "done compiling and indexing "$(NAME)


fclean : clean
	@rm -rf $(NAME)
	@$(MAKE) -C ./inc/libft/ fclean
clean :
	@rm -rf $(OBJECTS)
	@$(MAKE) -C ./inc/libft/ clean
re : fclean all

.PHONY : all re fclean clean