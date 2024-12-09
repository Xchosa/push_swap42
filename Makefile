# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 10:50:48 by poverbec          #+#    #+#              #
#    Updated: 2024/12/09 17:38:37 by poverbec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

MY_SOURCES = \
			lstadd_back_doubly.c \
			lstadd_front_doubly.c \
			lstclear_doubly.c \
			lstiter_doubly.c \
			lstlast_doubly.c \
			lstnew_doubly.c \
			

MY_OBJECTS= $(MY_SOURCES:.c=.o)
NAME = pushswap.a

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	$(CC) -rcs $(NAME) $(MY_OBJECTS) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(MY_OBJECTS)

fclean: clean 
	rm -f $(NAME)

re: fclean all 

.PHONY: re clean fclean all