# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAkefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 22:30:00 by aahadji           #+#    #+#              #
#    Updated: 2025/05/30 17:25:08 by aahadji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= .
LIBFT_DIR	= ./libft
PRINTF_DIR	= ./printf

SRC			= main.c push_swap_u.c tab_check.c calculate_check.c utils.c
OBJ			= $(SRC:.c=.o)

LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF		= $(PRINTF_DIR)/ft_printf.a

INCLUDES	= -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I.

all: $(NAME)

$(NAME): $(OBJ)
	@make bonus -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
