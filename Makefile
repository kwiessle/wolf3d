# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/20 11:28:07 by kwiessle          #+#    #+#              #
#    Updated: 2016/05/24 14:33:24 by kwiessle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= wolf3d

SRCS= srcs/main.c \
	  srcs/parsing.c \
	  srcs/checker.c \

OBJS= $(SRCS:.c=.o)
INCLUDES= -I libft/includes -I includes -I mlx/
LIBS= -L libft/ -lft -L mlx/ -lmlx -lm
FLAGS= -Wall -Wextra -Werror -O3 -Ofast -O2
FRAMEWORK= -framework AppKit -framework OpenGL

$(NAME):	$(OBJS)
	@make -C libft/
	@make -C mlx/
	@gcc -o $(NAME) $(OBJS) $(LIBS) $(FRAMEWORK)
	@echo "		\033[31;1m"
	@echo "		  ,__________,  ,____________,     "
	@echo "		  |          |  |             \    "
	@echo "		  |____.     |  |    ,___,     \   "
	@echo "		      /     /   |    |    \     \  "
	@echo "		     /     /    |    |     \     \ "
	@echo "		    /_____/     |____|     /     / "
	@echo "		  ,______________________./     /  "
	@echo "		  |                            /   "
	@echo "		  |__________________________./    "
	@echo "\033[0m"
	@echo "		  ZDTEAM                   2016"
	@echo "\n"


$(OBJS): %.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

all:	$(NAME)

clean:
	@make -C libft/ clean
	@make -C mlx/ clean
	@rm -f $(OBJS)
	@echo "\033[37mall $(NAME)_files.o are deleted\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\033[31m$(NAME) is deleted\033[0m"

re:		fclean all

.PHONY: all clean fclean re

