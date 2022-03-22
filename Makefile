# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 20:09:05 by jinacio-          #+#    #+#              #
#    Updated: 2022/03/10 22:53:47 by jinacio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

SRCDIR = src
OBJDIR = obj

COMPILE = push_swap.c utils.c validate.c swap.c shift_up.c shift_down.c push.c \
		quicksort.c utils2.c rotate_tree.c rotate_four_five.c \
		validate_extension.c rotate_anything.c push_aux.c

SRC = $(addprefix $(SRCDIR)/, $(COMPILE))
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

TAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJDIR) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
				$(CC) $(CFLAGS) -c $< -o $@	-I./src

$(OBJDIR):
		mkdir -p $(OBJDIR)

clean:
		rm -rf $(OBJDIR)

fclean: clean
		rm -f $(NAME)

re: fclean all
