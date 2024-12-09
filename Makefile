# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 10:50:48 by poverbec          #+#    #+#              #
#    Updated: 2024/12/05 11:40:15 by poverbec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror




all: $(NAME)
	$(AR) -rcs $(NAME) $(MY_OBJECTS) 

clean: 
	rm -f $(MY_OBJECTS)

fclean: clean 
	rm -f $(NAME)

re: fclean all 

.PHONY: re clean fclean all