# Define o compilador
CC = gcc

# Opções de compilação:
# -Wall: Habilita todos os avisos
# -g: Inclui informações para o depurador
# -I: Adiciona o diretório TADS para que o compilador encontre os arquivos .h
CFLAGS = -Wall -g -I./TADS

# Nome do executável
EXECUTABLE = programa

# Define os diretórios de origem e destino
SRC_DIR = ./funcoes
OBJ_DIR = ./processoas

# Encontra automaticamente todos os arquivos .c na pasta 'funcoes'
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# Cria os nomes dos arquivos objeto na pasta de destino
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

# Regra principal para compilar e linkar
all: $(EXECUTABLE)

# Regra para linkar os arquivos objeto e criar o executável
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Regra genérica para compilar qualquer arquivo .c da pasta 'funcoes'
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa os arquivos gerados
clean:
	rm -f $(OBJ_DIR)/*.o $(EXECUTABLE)