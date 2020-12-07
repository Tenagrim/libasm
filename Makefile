.PHONY: all clean fclean re
NAME=libasm.a
SRC=ft_strlen.s
OBJ=$(OBJ:.s=.o)

all: $(NAME)

%.o: %.s
	nasm -c $< -o $@

test: main.c $(NAME)
	gcc main.c $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
