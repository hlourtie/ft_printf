# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 11:09:20 by hlourtie          #+#    #+#              #
#    Updated: 2020/11/28 20:56:08 by hlourtie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Project name
NAME 		:= libftprintf.a

#Project build and directories
SRCDIR		:= ./src/
SRCNAMES	:= $(shell ls $(SRCDIR)| grep -E ".+\.c")
SRC 		:= $(addprefix $(SRCDIR), $(SRCNAMES))
INC 		:= ./inc/
BUILDDIR 	:= ./build/
BUILDOBJS 	:= $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

# Libft builds and dirs
LIBDIR		:= ./libft/
LIBFT 		:= ./libft/libft.a
LIBINC		:= ./libft/inc/
LIBNAMES	:= $(shell ls $(LIBDIR)| grep -E ".+\.c")
LIBOBJ		:= $(addprefix $(LIBDIR), $(LIBNAMES:.c=.o))

# Optimization and Compiler flags and commands
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Main rule
all: $(BUILDDIR) $(LIBFT) $(NAME)

# Object dir rule
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Objects rule
$(BUILDDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) -I$(LIBINC) -I$(INC) -o $@ -c $<
# Project file rule
$(NAME): $(BUILDOBJS)
	ar rcs $(NAME) $(BUILDOBJS) $(LIBOBJ) $(LIBFT)
	ranlib $(NAME)

# Libft rule
$(LIBFT):
	make -C $(LIBDIR)

# Cleaning up the build files
clean:
	rm -rf $(BUILDDIR)
	make -C $(LIBDIR) clean

# Getting rid of the project file
fclean: clean
	rm -rf $(NAME)
	make -C $(LIBDIR) fclean

# Do both of the above
re: fclean all

# Just in case those files exist in the root dir
.PHONY: all fclean clean re