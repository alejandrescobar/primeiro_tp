# Define o nome do executável final
TARGET = meu_programa

# Lista todos os arquivos de implementação (.c)
SRCS = main.c dados_pacote.c lista_de_pacotes.c

# Define os arquivos objeto intermediarios (.o)
OBJS = $(SRCS:.c=.o)

# Define as flags do compilador GCC
# -Wall: ativa todos os avisos de compilacao
CFLAGS = -Wall

# A regra padrão 'all' compila o programa
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

# Regra para compilar cada arquivo .c em um arquivo .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra 'clean' para remover os arquivos compilados
clean:
	rm -f $(TARGET) $(OBJS)