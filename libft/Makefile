# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 18:46:09 by hlourtie          #+#    #+#              #
#    Updated: 2020/11/25 19:08:26 by hlourtie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# library name
NAME	:= libft.a

CFLAGS	:= -Wall -Wextra -Werror -Iinc -c
FILES:= $(shell ls | grep -E ".+\.c")
OBJECTS	:= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
	
$(OBJECTS): $(FILES)
	@gcc $(CFLAGS) $(FILES)

fclean : clean
	@rm -rf $(NAME)

clean :
	@rm -rf $(OBJECTS)

re : fclean all

.PHONY : re fclean clean