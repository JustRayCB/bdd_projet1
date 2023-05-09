CXXFLAGS+=-std=c++17 -g -Wall -Wextra -Wpedantic -D_GNU_SOURCE -Werror=all -O2
CXX=g++
LDLIBS+=-lmysqlcppconn
OBJ_DIR=bin

ifeq ($(wildcard $(OBJ_DIR)),)
    # S'il n'existe pas, crée le répertoire
    $(shell mkdir $(OBJ_DIR))
endif

main: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)
