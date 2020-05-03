##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC = 	$(wildcard fonctions/*.c)

OBJ = $(SRC:.c=.o)

NAME = my_rpg

INCLUDE = -I ./include/

CFLAGS = $(INCLUDE) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -Wall -Wextra  -g

all :	$(NAME)
	$(shell mkdir -p "save")

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
