all: bin/burbuja bin/floyd bin/hanoi bin/heapsort bin/insercion bin/mergesort bin/quicksort bin/seleccion

bin/burbuja: src/burbuja.cpp
	@g++ src/burbuja.cpp -o bin/burbuja
	@echo "Compilando algoritmo burbuja..."

bin/floyd: src/floyd.cpp
	@g++ src/floyd.cpp -o bin/floyd
	@echo "Compilando algoritmo de Floyd..."

bin/hanoi: src/hanoi.cpp
	@g++ src/hanoi.cpp -o bin/hanoi
	@echo "Compilando algoritmo de las torres de Hanoi..."

bin/heapsort: src/heapsort.cpp
	@g++ src/heapsort.cpp -o bin/heapsort
	@echo "Compilando algoritmo heapsort..."

bin/insercion: src/insercion.cpp
	@g++ src/insercion.cpp -o bin/insercion
	@echo "Compilando algoritmo de inserción..."

bin/mergesort: src/mergesort.cpp
	@g++ src/mergesort.cpp -o bin/mergesort
	@echo "Compilando algoritmo mergesort..."

bin/quicksort: src/quicksort.cpp
	@g++ src/quicksort.cpp -o bin/quicksort
	@echo "Compilando algoritmo quicksort..."

bin/seleccion: src/seleccion.cpp
	@g++ src/seleccion.cpp -o bin/seleccion
	@echo "Compilando algoritmo de selección..."

clean:
	@rm -f bin/*
	@echo "Eliminando ejecutables..."
