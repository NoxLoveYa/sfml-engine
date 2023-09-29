##
## EPITECH PROJECT, 2023
## my_engine
## File description:
## Makefile
##

CPPFLAGS = -lsfml-window -lsfml-graphics -lsfml-system -lsfml-audio
SRC = $(wildcard src/*.c* src/*/*.c*)
NAME = my_engine

all: 
	g++ -o $(NAME) $(SRC) $(CPPFLAGS)

clean:
	$(RM) $(NAME)

re: clean all

test:
	make re; clear; ./$(NAME)
