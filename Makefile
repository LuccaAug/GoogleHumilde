CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++14 -ggdb


all: bin/main bin/teste_dataset bin/teste_indice_invertido bin/teste_ranking

clean:
	rm -rf bin/*

run: bin/main
	clear
	./bin/main

teste_dataset: bin/teste_dataset.o
	clear
	./bin/teste_dataset

teste_indice_invertido: bin/teste_indice_invertido.o
	clear
	./bin/teste_indice_invertido

teste_ranking: bin/teste_ranking.o
	clear
	./bin/teste_ranking

bin/dataset.o: src/dataset.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/indice_invertido.o: bin/dataset.o src/indice_invertido.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/ranking.o: bin/dataset.o bin/indice_invertido.o src/ranking.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/teste_dataset: bin/dataset.o src/dataset.teste.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

bin/teste_indice_invertido: bin/indice_invertido.o src/indice_invertido.teste.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@

bin/teste_ranking: bin/ranking.o src/ranking.teste.cpp
	$(CXX) $(CXX_FLAGS) -I include/ $^ -o $@
	
bin/main: bin/dataset.o bin/indice_invertido.o bin/ranking.o src/main.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@
