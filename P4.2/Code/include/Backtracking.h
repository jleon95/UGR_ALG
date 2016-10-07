#ifndef BACK
#define BACK

#include <iostream>
#include <vector>
#include "Grafo.h"

using namespace std;

class Backtracking{

private:

	Grafo grafo;

	vector<int> mejor_camino;
	vector<int> camino_actual;

	int mejor_coste;

	double heuristica(vector<int> &camino);
	void FBacktracking(int coste_actual);

public:

	Backtracking(char* nombre_archivo);
	void FBacktracking();
	vector<int> getMejorCamino();
	int getMejorCoste();
	
};

#endif