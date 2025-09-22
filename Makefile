# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c99 -g

# Diretórios
SRC_DIR = Funções
OBJ_DIR = processos
TADS_DIR = TADS

# Arquivos fonte
SRCS = $(SRC_DIR)/dados_pacote.c $(SRC_DIR)/galpao.c $(SRC_DIR)/lista_de_pacotes.c $(SRC_DIR)/main.c $(SRC_DIR)/Tad_Drone.c

# Arquivos objeto
OBJS = $(OBJ_DIR)/dados_pacote.o $(OBJ_DIR)/galpao.o $(OBJ_DIR)/lista_de_pacotes.o $(OBJ_DIR)/main.o $(OBJ_DIR)/Tad_Drone.o

# Nome do executável
TARGET = programa

# Regra principal
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regras para compilar cada arquivo objeto
$(OBJ_DIR)/dados_pacote.o: $(SRC_DIR)/dados_pacote.c $(TADS_DIR)/dados_pacote.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/dados_pacote.c -o $(OBJ_DIR)/dados_pacote.o

$(OBJ_DIR)/galpao.o: $(SRC_DIR)/galpao.c $(TADS_DIR)/galpao.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/galpao.c -o $(OBJ_DIR)/galpao.o

$(OBJ_DIR)/lista_de_pacotes.o: $(SRC_DIR)/lista_de_pacotes.c $(TADS_DIR)/lista_de_pacotes.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/lista_de_pacotes.c -o $(OBJ_DIR)/lista_de_pacotes.o

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/Tad_Drone.o: $(SRC_DIR)/Tad_Drone.c $(TADS_DIR)/Tad_Drone.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Tad_Drone.c -o $(OBJ_DIR)/Tad_Drone.o

# Regra para limpar os arquivos compilados
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)

# Regra para recompilar tudo
re: clean all

# Ajuda
help:
	@echo "Makefile para compilar o projeto"
	@echo "Comandos disponíveis:"
	@echo "  make all    - Compila o projeto (padrão)"
	@echo "  make clean  - Remove arquivos objeto e executável"
	@echo "  make re     - Recompila o projeto do zero"
	@echo "  make help   - Mostra esta ajuda"

.PHONY: all clean re help