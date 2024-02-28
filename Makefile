# SFML Include and Lib paths
INCLUDE_SFML = SFML/include
LIB_SFML = SFML/lib

HEADERS = src/Headers


# Source directory
SRC_DIR = src


# Find all cpp files in the source directory
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)


# Object files derived from cpp files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, %.o, $(SRC_FILES))


all: compile link clean


compile: $(OBJ_FILES)


%.o: $(SRC_DIR)/%.cpp
	g++ -I$(INCLUDE_SFML) -I$(HEADERS) -c $< -o $@ -DSFML_STATIC


link: $(OBJ_FILES)
	g++ $^ -o main -L$(LIB_SFML) -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32

clean:
	rm -rf *.o