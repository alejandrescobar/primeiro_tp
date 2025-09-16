# Define o compilador
CC = gcc

# Define as opções de compilação:
# -Wall: Habilita todos os avisos (warnings)
# -g: Inclui informações para o depurador (debugger)
CFLAGS = -Wall -g

# Define o nome do arquivo executável
EXECUTABLE = programa

# Define os arquivos de código-fonte
SOURCES = main.c dados_pacote.c lista_de_pacotes.c galpao.c

# Cria automaticamente os nomes dos arquivos objeto (.o) a partir dos arquivos .c
OBJECTS = $(SOURCES:.c=.o)

# Regra principal: constrói o executável a partir dos arquivos objeto
all: $(EXECUTABLE)

# Regra para linkar os arquivos objeto e criar o executável
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para compilar cada arquivo .c em .o
# A variável $< representa o nome do arquivo .c
# A variável $@ representa o nome do arquivo .o
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Limpar os arquivos gerados (arquivos objeto e executável)
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)