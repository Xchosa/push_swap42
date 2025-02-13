# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 10:50:48 by poverbec          #+#    #+#              #
#    Updated: 2025/02/13 09:52:20 by poverbec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LIBFT	= libft/libft.a
NAME 	= push_swap
NAME_Checker = checker

VPATH= src:src/list_push_swap:src/sorting_algorithm:src/push_commands:src/bonus/
MY_SOURCES = \
			lstadd_back_ps.c \
			lstadd_front_ps.c \
			lstclear_ps.c \
			lstiter_ps.c \
			lstlast_ps.c \
			lstnew_ps.c \
			lstsize_ps.c \
			main.c \
			sorting_a_into_b.c \
			sorting_b_into_a.c \
			sorting_and_moving.c \
			parse_nbr.c \
			sorting_small.c \
			sorting_stacks_helper.c \
			push_swap_comands.c \
			push_swap_rev_rotate.c \
			push_swap_comands_swap.c \
			sort_algo.c \
			testprint.c

MY_SOURCES_BONUS = \
				checker.c \
				bonus_commands_1.c \
				bonus_commands_2.c \
				bonus_commands.c \
				lstadd_back_ps.c \
				lstadd_front_ps.c \
				lstclear_ps.c \
				lstiter_ps.c \
				lstlast_ps.c \
				lstnew_ps.c \
				lstsize_ps.c \
				sorting_a_into_b.c \
				sorting_b_into_a.c \
				sorting_and_moving.c \
				parse_nbr.c \
				sorting_small.c \
				sorting_stacks_helper.c \
				push_swap_comands.c \
				push_swap_rev_rotate.c \
				push_swap_comands_swap.c \
				sort_algo.c 
				
				

MY_OBJECTS=$(MY_SOURCES:.c=.o)
MY_OBJECTS_BONUS = $(MY_SOURCES_BONUS:.c=.o)

# ---------- COLORS AND STUFF ---------- #
Color_Off = \033[0m
BIYellow = \033[1;93m
Yellow = \033[0;33m
BGreen = \033[1;32m 
On_Yellow = \033[43m
On_Green = \033[42m
Red = \033[0;31m

all: $(LIBFT) $(NAME)

$(NAME): $(MY_OBJECTS)
	@echo "$(BIYellow) Compiling $(NAME) $(Color_Off)"
	@$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIBFT) -o $(NAME)
	@if [ -f $(NAME) ]; then \
		echo "$(On_Yellow)------------------------------------------$(Color_Off)"; \
		echo "$(BGreen)PROCESS COMPLETED SUCCESSFULLY!$(Color_Off)"; \
		echo "$(On_Green)------------------------------------------$(Color_Off)"; \
	else \
		echo "$(Red)failed to compile $(NAME) $(Color_Off)"; \
		exit 1; \
	fi

bonus: $(MY_OBJECTS_BONUS)
	@echo "$(BIYellow) Compiling $(NAME_Checker) $(Color_Off)"
	@$(CC) $(CFLAGS) $(MY_OBJECTS_BONUS) $(LIBFT) -o $(NAME_Checker)
	@if [ -f $(NAME_Checker) ]; then \
		echo "$(On_Yellow)------------------------------------------$(Color_Off)"; \
		echo "$(BGreen)PROCESS COMPLETED SUCCESSFULLY!$(Color_Off)"; \
		echo "$(On_Green)------------------------------------------$(Color_Off)"; \
	else \
		echo "$(Red)failed to compile $(NAME_Checker) $(Color_Off)"; \
		exit 1; \
	fi
	
$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(Yellow)-----Removing Object Files--------$(Color_Off)"
	@rm -f $(MY_OBJECTS) $(MY_OBJECTS_BONUS)

fclean: clean
	@echo "$(On_Yellow)Removing Executables...$(Color_Off)"
	@rm -f $(NAME) $(NAME_Checker)
	make -C libft fclean

re: fclean all

f: fclean
f: CFLAGS += -g -fsanitize=address
f: $(NAME) $(NAME_Checker)

.PHONY: re clean fclean all
