CC = gcc
CFLAGS = -Wall

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

programa: $(OBJ)
	$(CC) $(OBJ) -o programa

clean:
	del /Q *.o *.exe

run: programa
	./programa