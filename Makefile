# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 04:21:37 by ebatchas          #+#    #+#              #
#    Updated: 2018/11/25 17:03:22 by ebatchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

SRCDIR=.
HEADDIR=include
LIBDIR=lib

CFLAGS=-I$(HEADDIR) -Wall -Wextra -Werror -g -w
LDFLAGS=-I$(HEADDIR) -L$(LIBDIR) -lSDL2 -lSDL2_mixer -lSDL2_ttf

SRC=$(SRCDIR)/main.c)\
	$(SRCDIR)/solver.c\
	$(SRCDIR)/fillit.c\
	$(SRCDIR)/fillit_valide.c\
	$(SRCDIR)/utils.c\
	$(SRCDIR)/input.c\
	$(SRCDIR)/init_sdl.c\
	$(SRCDIR)/tetriminos.c

OBJ=$(LIBDIR)/tetriminos.o\
	$(LIBDIR)/solver.o\
	$(LIBDIR)/utils.o\
	$(LIBDIR)/input.o\
	$(LIBDIR)/main.o\
	$(LIBDIR)/fillit.o\
	$(LIBDIR)/init_sdl.o\
	$(LIBDIR)/fillit_valide.o
NAME = fillit

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $^
	rm -rf "$@.dSYM"

$(LIBDIR)/%.o:$(wildcard $(HEADDDIR)/*.h)

$(LIBDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean fclean

clean:
	rm -rf $(LIBDIR)/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
