# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 10:50:48 by poverbec          #+#    #+#              #
#    Updated: 2025/01/09 15:11:04 by poverbec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror #-I. -v
LIBFT=libft/libft.a

VPATH= 	src:src/list_push_swap:src/sort

MY_SOURCES = \
			lstadd_back_.c \
			lstadd_front_ps.c \
			lstclear_ps.c \
			lstiter_ps.c \
			lstlast_ps.c \
			lstnew_ps.c \
			lstsize_ps.c \
			push_swap.c \
			init_object.c \
			push_swap_utilis.c \
			handle_stack_ab.c 

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
