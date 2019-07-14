# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/28 14:35:27 by kfalia-f          #+#    #+#              #
#    Updated: 2019/07/14 17:07:19 by kfalia-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror

SRCF = srcs

SRC = $(SRCF)/main.c \
	  $(SRCF)/env.c \
	  $(SRCF)/readline.c \
	  $(SRCF)/interpretator.c \
	  $(SRCF)/cd.c \
	  $(SRCF)/binares.c \
	  $(SRCF)/check_binaries.c \
	  $(SRCF)/setenv.c

LIBFT_FOLDER = libft

LIBFT = -L $(LIBFT_FOLDER) -lft

OBJECTS = $(SRC:.c=.o)

HEADERS = -I includes -I $(LIBFT_FOLDER)/includes

%.o: %.c $(INCLUDES)
	@gcc $(FLAGS) $(HEADERS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(LIBFT_FOLDER)
	@make -C $(LIBFT_FOLDER) clean
	@gcc $(FLAGS) -o $(NAME) $(HEADERS) $(OBJECTS) $(LIBFT)

clean:
	@rm -f $(OBJECTS)
	@make -C $(LIBFT_FOLDER) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_FOLDER) fclean

re: fclean all

test:
	@gcc -g $(FLAGS) -o $(NAME) $(HEADERS) $(SRC) $(LIBFT)
