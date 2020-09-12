# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: henrylourtie <henrylourtie@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 18:46:09 by hlourtie          #+#    #+#              #
#    Updated: 2020/09/12 11:48:28 by henrylourti      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# library name
NAME	:= libft.a

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -Iinc -c
FILES:= $(shell ls | grep -E ".+\.c")
OBJECTS	:= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJ)
	
$(OBJECTS): $(FILES)
	@gcc $(CFLAGS) $(FILES)

fclean :
	@rm -rf $(NAME)

clean :
	@rm -rf $(OBJECTS_BONUS)

re : fclean all

.PHONY : re fclean clean