# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/20 11:28:07 by kwiessle          #+#    #+#              #
#*   Updated: 2016/05/29 16:07:37 by kwiessle         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME= wolf3d

SRCS= srcs/main.c \
	  srcs/init_env.c \
	  srcs/image.c \
	  srcs/raycasting.c \
	  srcs/searchinlist.c \
	  srcs/key_function.c \
	  srcs/key_hook.c \
	  srcs/texture.c \
	  srcs/get_texture.c \
	  srcs/levels.c

OBJS= $(SRCS:.c=.o)
INCLUDES= -I libft/includes -I includes -I mlx/
LIBS= -L libft/ -lft -L mlx/ -lmlx -lm
FLAGS= -Wall -Wextra -Werror -O3 -Ofast -O2
FRAMEWORK= -framework AppKit -framework OpenGL

$(NAME):	$(OBJS)
	@make -C libft/
	@make -C mlx/
	@gcc -o $(NAME) $(OBJS) $(LIBS) $(FRAMEWORK)
	@echo "	\033[31;1m"
	@echo "	  ,__________,  ,____________,     "
	@echo "	  |          |  |             \    "
	@echo "	  |____.     |  |    ,___,     \   "
	@echo "	      /     /   |    |    \     \  "
	@echo "	     /     /    |    |     \     \ "
	@echo "	    /_____/     |____|     /     / "
	@echo "	  ,______________________./     /  "
	@echo "	  |                            /   "
	@echo "	  |__________________________./\n\033[0;1m "


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

norme: fclean
	@norminette srcs/
	@norminette includes/
	@norminette libft/

.PHONY: all clean fclean re

