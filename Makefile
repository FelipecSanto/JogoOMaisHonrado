# Diretório de destino para os arquivos .o
OBJ_DIR = objects

# Lista de todos os arquivos .cpp no diretório src
CPP_FILES := $(wildcard src/*.cpp)

# Lista de arquivos .o gerados a partir dos arquivos .cpp
OBJ_FILES := $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(CPP_FILES))

# Compilação dos arquivos .cpp para arquivos .o 
$(OBJ_DIR)/%.o: src/%.cpp | create_obj_dir
	g++ -c -Iinclude \
	-Iinclude/Entes \
	$< -o $@

# Regra padrão para construir o executável
all: clear compile link

# Regra para criar o diretório de objetos
create_obj_dir:
	mkdir -p $(OBJ_DIR)

compile: $(OBJ_FILES)
    
link:
	g++ $(OBJ_FILES) -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Regra para rodar o executável
run:
	./main

# Limpar os arquivos .o e o executável
clear:
	rm -f $(OBJ_DIR)/*.o main

.PHONY: all create_obj_dir compile link run clear

# Como usar o Makefile
# make all -> Compila tudo e gera o executável (apaga os arquivos .o e o executável antigos)
# make run -> Roda o executável