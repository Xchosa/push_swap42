# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 10:50:48 by poverbec          #+#    #+#              #
#    Updated: 2024/12/11 14:44:52 by poverbec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT=libft/libft.a

MY_SOURCES = \
			lstadd_back_doubly.c \
			lstadd_front_doubly.c \
			lstclear_doubly.c \
			lstiter_doubly.c \
			lstlast_doubly.c \
			lstnew_doubly.c \
			lstsize_doubly.c \
			push_swap.c \
			push_swap_utilis.c \
			

MY_OBJECTS=$(MY_SOURCES:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(MY_OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIBFT) -o $(NAME)
#$(CC) -rcs $(NAME) $(MY_OBJECTS) 
# ar -rcs $(NAME) $(MY_OBJECTS)

# $(EXEC): $(MY_OBJECTS)
# 	$(CC) $(CFLAGS) $(MY_OBJECTS) -o

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(MY_OBJECTS)

fclean: clean 
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all