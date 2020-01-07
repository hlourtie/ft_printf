# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 18:46:09 by hlourtie          #+#    #+#              #
#    Updated: 2019/11/12 17:39:31 by hlourtie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a

CC		:= gcc
C_FLAGS	:= -Wall -Wextra -Werror
C_FILES:= ft_atoi.c\
					ft_bzero.c\
					ft_calloc.c\
					ft_isalnum.c\
					ft_isalpha.c\
					ft_isascii.c\
					ft_isdigit.c\
					ft_isprint.c\
					ft_itoa.c\
					ft_memccpy.c\
					ft_memchr.c\
					ft_memcmp.c\
					ft_memcpy.c\
					ft_memmove.c\
					ft_memset.c\
					ft_putchar_fd.c\
					ft_putendl_fd.c\
					ft_putnbr_fd.c\
					ft_putstr_fd.c\
					ft_split.c\
					ft_strchr.c\
					ft_strdup.c\
					ft_strjoin.c\
					ft_strlcat.c\
					ft_strlcpy.c\
					ft_strlen.c\
					ft_strmapi.c\
					ft_strncmp.c\
					ft_strnstr.c\
					ft_strrchr.c\
					ft_strtrim.c\
					ft_substr.c\
					ft_tolower.c\
					ft_toupper.c\
					ft_strjoin_free_bonus.c\
					ft_strndup_bonus.c\

C_FILES_BONUS := ft_lstadd_back_bonus.c\
					ft_lstadd_front_bonus.c\
					ft_lstclear_bonus.c\
					ft_lstdelone_bonus.c\
					ft_lstiter_bonus.c\
					ft_lstlast_bonus.c\
					ft_lstmap_bonus.c\
					ft_lstnew_bonus.c\
					ft_lstsize_bonus.c\
					$(C_FILES)

INC := libft.h

SOURCES	:= $(C_FILES)
INCUDES	:= $(addprefix -I , $(INC))
INCUDES_BONUS	:= $(addprefix -I , $(INC_BONUS))
OBJECTS	:= $(patsubst %.c, %.o, $(C_FILES))
OBJECTS_BONUS := $(patsubst %.c, %.o, $(C_FILES_BONUS))

all: $(NAME)

%.o : %.c
	@$(CC) $(C_FLAGS) -c $< -o $@ $(INCUDES)

$(NAME) : $(OBJECTS)
	@ar -rc $@ $(OBJECTS)
	@ranlib $@
	

bonus : $(OBJECTS_BONUS)
	@ar -rc $(NAME) $(OBJECTS_BONUS)
	@ranlib $(NAME)
	@echo "all done bonus"

fclean :
	@rm -rf $(NAME)

clean :
	@rm -rf $(OBJECTS_BONUS)

re : fclean all

.PHONY : re fclean clean