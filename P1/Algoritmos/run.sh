#!/bin/bash


# Compila si es necesario.

#make


# Ejecuta los algoritmos muchas veces (las mínimas necesarias al menos).
# Si no quieres ejecutar alguno, lo comentas o lo quitas.

# Los tamaños de los algoritmos de búsqueda hay que ajustarlos mejor
# porque luego vamos a tener que comparar los n^2 con los nlogn y
# si son demasiado pequeños unos dan tiempo 0
# pero si son demasiado grandes, otros tardan la vida.


echo "" > data/burbuja.dat
for ((I=5000;I<100001;I=I+5000))
do
	bin/burbuja $I >> data/burbuja.dat
done

echo "" > data/floyd.dat
for ((I=100;I<1551;I=I+50))
do
	bin/floyd $I >> data/floyd.dat
done

echo "" > data/hanoi.dat
for ((I=8;I<34;I=I+1))
do
	bin/hanoi $I >> data/hanoi.dat
done

echo "" > data/heapsort.dat
for ((I=100000;I<3000001;I=I+100000))
do
	bin/heapsort $I >> data/heapsort.dat
done

echo "" > data/insercion.dat
for ((I=5000;I<305001;I=I+12000))
do
	bin/insercion $I >> data/insercion.dat
done

echo "" > data/mergesort.dat
for ((I=500000;I<7000001;I=I+500000))
do
	bin/mergesort $I >> data/mergesort.dat
done

echo "" > data/quicksort.dat
for ((I=100000;I<3000001;I=I+100000))
do
	bin/quicksort $I >> data/quicksort.dat
done

echo "" > data/seleccion.dat
for ((I=5000;I<100001;I=I+5000))
do
	bin/seleccion $I >> data/seleccion.dat
done