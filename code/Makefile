CXXFLAGS+=-std=c++17 -g -Wall -Wextra -Wpedantic -D_GNU_SOURCE -Werror=all -O2
CXX=g++
LDLIBS+=-lmysqlcppconn -lpugixml
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
