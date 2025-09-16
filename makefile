# Define os arquivos fonte e de objeto
SOURCES = main.c dados_pacote.c lista_de_pacotes.c  # <--- Adicione o novo arquivo aqui!
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = programa

# Regra principal para construir o programa
all: $(EXECUTABLE)

# Linkar os arquivos objeto para criar o executável
$(EXECUTABLE): $(OBJECTS)
	gcc -Wall -g -o $@ $(OBJECTS)

# Compilar cada arquivo .c em seu respectivo .o
%.o: %.c
	gcc -Wall -g -c $<

# Limpar arquivos gerados
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
