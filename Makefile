# Diretório de destino para os arquivos .o
OBJ_DIR = objects

# Lista de todos os arquivos .cpp no diretório src
CPP_FILES := $(wildcard src/*.cpp)

# Lista de arquivos .o gerados a partir dos arquivos .cpp
OBJ_FILES := $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(CPP_FILES))

# Compilação dos arquivos .cpp para arquivos .o 
$(OBJ_DIR)/%.o: src/%.cpp
	g++ -c	-Iinclude \
	-ISFML/include \
	-Iinclude/Entes \
    $< -o $@

# Regra padrão para construir o executável
all: create_obj_dir clear compile link

# Regra para criar o diretório de objetos
create_obj_dir:
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

compile: $(OBJ_FILES)
	
link:
	g++ $(OBJ_FILES) -o main -LSFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lsfml-audio

# Regra para rodar o executável
run:
	./main

# Limpar os arquivos .o e o executável
clear:
	@if exist $(OBJ_DIR)/*.o del /Q $(OBJ_DIR)\*.o
	@if exist main del main


# Como usar o Makefile
# make all -> Compila tudo e gera o executável (apaga os arquivos .o e o executável antigos)
# make run -> Roda o executável