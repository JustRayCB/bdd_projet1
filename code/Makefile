CXXFLAGS+=-std=c++17 -g -Wall -Wextra -Wpedantic -D_GNU_SOURCE -Werror=all -O2 -I/opt/homebrew/Cellar/mysql-connector-c++/8.0.33/include/ -I/opt/homebrew/Cellar/pugixml/1.13/include/

CXX=g++
LDLIBS+=-L/opt/homebrew/Cellar/mysql-connector-c++/8.0.33/lib64/ -L/opt/homebrew/Cellar/pugixml/1.13/lib/ -lmysqlcppconn -lpugixml

OBJ_DIR=bin

ifeq ($(wildcard $(OBJ_DIR)),)
    # S'il n'existe pas, crée le répertoire
    $(shell mkdir $(OBJ_DIR))
endif

main: main.cpp $(OBJ_DIR)/database.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

$(OBJ_DIR)/database.o: database.cpp database.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(LDLIBS)

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm main
