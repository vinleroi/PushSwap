# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aahadji <aahadji@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 23:00:00 by aahadji           #+#    #+#              #
#    Updated: 2025/05/30 17:47:10 by aahadji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

SRC     = ft_atoi.c ft_isdigit.c ft_itoa.c ft_libft.c ft_split.c \
          ft_strcmp.c ft_strdup.c ft_strlen.c ft_substr.c ft_calloc.c 

BONUS   = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
          ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstmax.c ft_lstnew_bonus.c \
          ft_lstsize_bonus.c 

OBJS        = $(SRC:.c=.o)
OBJS_BONUS  = $(BONUS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

bonus: $(NAME) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
