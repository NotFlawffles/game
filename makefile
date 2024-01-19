CXX = c++
CXXFLAGS = -Wall -Wextra -pedantic -ggdb -o
OBJECT = game
SRC = $(shell find src/ -type f -name *.cpp)
INSTALLATION_TARGET = /usr/bin/game
LIBS = -lSDL2main -lSDL2

default: $(SRC)
	@$(CXX) $(CXXFLAGS) $(OBJECT) $(SRC) $(LIBS)

clean: $(OBJECT)
	@rm $(OBJECT)

install: $(INSTALLATION_TARGET)
	@make default
	@sudo mv $(OBJECT) $(INSTALLATION_TARGET)

uninstall: $(INSTALLATION_TARGET)
	@sudo rm $(INSTALLATION_TARGET)
