# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 10:50:48 by poverbec          #+#    #+#              #
#    Updated: 2024/12/16 15:09:41 by poverbec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror #-I. -v
LIBFT=libft/libft.a

VPATH= 	src:src/doubly_list_func:src/sort

MY_SOURCES = \
			lstadd_back_doubly.c \
			lstadd_front_doubly.c \
			lstclear_doubly.c \
			lstiter_doubly.c \
			lstiter_doubly_index.c \
			lstlast_doubly.c \
			lstnew_doubly.c \
			lstsize_doubly.c \
			push_swap.c \
			init_object.c \
			push_swap_utilis.c \
			push_swap_utilis2.c \
			handle_stack_ab.c \

MY_OBJECTS=$(MY_SOURCES:.c=.o)
NAME = push_swap

all: $(LIBFT) $(NAME)

$(NAME): $(MY_OBJECTS) 
	$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIBFT) -o $(NAME)
# cc   -Wall -Wextra -Werror ….o libft/libft.a -o push_swap
#$(CC) -rcs $(NAME) $(MY_OBJECTS) 
# ar -rcs $(NAME) $(MY_OBJECTS)


$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(MY_OBJECTS)

fclean: clean 
	rm -f $(NAME)
# make -C libft fclean

re: fclean all

f: fclean
f: CFLAGS += -g -fsanitize=address
f: $(NAME)

.PHONY: re clean fclean all
