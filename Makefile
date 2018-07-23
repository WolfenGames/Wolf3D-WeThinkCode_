# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwolf <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 10:11:48 by jwolf             #+#    #+#              #
#    Updated: 2018/07/17 07:20:38 by jwolf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CFLAGS += -Wextra -Wall -I./includes

ATTACH = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

C = gcc

HEADERS = includes

DIR_S = srcs

DIR_O = obj

SOURCES = main.c load_file.c map.c window.c keyhandle.c error.c draw_back.c \
			extra1.c draw_mini.c draw_wall.c

OBJECTS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

$(DIR_O)/%.o:		$(DIR_S)/%.c $(HEADERS)/$(NAME).h
	@echo "\033[1;35;m[Compiling $<] \t\033[0m"
	@$(C) $(CFLAGS) -c -o $@ $<

$(NAME): temporary $(OBJECTS)
	@echo "\033[1;34;m[Making... Pizza]\033[0m"
	@make -C libft
	$(C) $(CFLAGS) -o $(NAME) $(OBJECTS) $(ATTACH)

all: temporary $(NAME)

temporary:
	@mkdir -p obj

clean:
	@echo "\033[1;33;m[Cleaning]\033[0m"
	@make -C libft clean
	@rm -rf $(OBJECTS)

fclean: clean
	@echo "\033[1;32;m[Force Cleaning]\033[0m"
	@make -C libft fclean
	@rm -rf $(NAME)
	@rm -rf $(DIR_O)

re: fclean clean all
	@echo "\033[1;31;m[Recompiled]\033[0m"

run: $(NAME)
	./$(NAME)

.PHONY: fclean clean all re
