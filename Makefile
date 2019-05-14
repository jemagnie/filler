# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jemagnie <jemagnie@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/07 12:14:16 by jemagnie     #+#   ##    ##    #+#        #
#    Updated: 2018/12/18 15:32:53 by jemagnie    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
NAME = jemagnie.filler
FLAG = -Wall -Wextra -Werror
SRC = srcs/filler.c srcs/solver.c srcs/tool.c
SEG = -fsanitize=address
OBJ = $(SRC:.c=.o)

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	@gcc $(FLAG) libft/libft.a $(OBJ) -o $(NAME)
	@echo "jemagnie.filler created"

%.o: %.c ./include/filler.h
	@gcc $(FLAG) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY : all clean fclean re
