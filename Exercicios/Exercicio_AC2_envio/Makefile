# Nome do nosso executável
APP = labirinto.exe

# Compilador
CC = gcc

# Flags de aviso para não deixarmos passar nenhum erro bobo
CFLAGS = -Wall

# Lista de todos os nossos módulos separados por pastas
FONTES = main.c lista.c pilha.c mapa.c

# Regra padrão (roda ao digitar apenas mingw32-make)
all: build

# Regra para compilar e juntar tudo
build:
	$(CC) $(CFLAGS) $(FONTES) -o $(APP)

# Regra para compilar e já rodar o jogo (mingw32-make run)
run: build
	./$(APP)

# Regra para limpar o executável antigo (mingw32-make clean)
clean:
	del $(APP)