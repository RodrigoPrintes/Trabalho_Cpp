# Configurações do projeto
TARGET = main
SRCDIR = src
INCDIR = inc
OBJDIR = obj
LIBDIR = lib
OUTPUTDIR = output

# Compilador e flags
CC = g++
CFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = -lavformat -lavcodec -lavutil

# Arquivos fonte, objetos e bibliotecas
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Diretivas de compilação
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -I$(INCDIR) -L$(LIBDIR) $^ -o $(OUTPUTDIR)/$@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	rm -f $(OBJDIR)/*.o $(OUTPUTDIR)/$(TARGET)
