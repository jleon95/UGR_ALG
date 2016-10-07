#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include "Backtracking.h"
#include "Grafo.h"

using namespace std;

const int INFINITO = numeric_limits<int>::max();

bool EstaEn(int dato, const vector<int> &circuito) {

	bool encontrado = false;

	for (int i = 0 ; i < circuito.size() && !encontrado ; i++)
	
		if (circuito[i] == dato)
			
			encontrado = true;
			
	return encontrado;
	
}

Backtracking::Backtracking(char* nombre_archivo){

	grafo = CargarGrafo(nombre_archivo);

	mejor_coste = INFINITO;
	camino_actual.push_back(0);

}

double Backtracking::heuristica(vector<int> &camino){

	double valoracion = 0;
	bool encontrado;

	for(int i=0; i<grafo.size() ; i++){

		encontrado = false;

		for(int j = 0 ; j < camino.size() && !encontrado ; j++){

			encontrado = camino[j] == i;

		}

		if(!encontrado)

			valoracion += grafo.getAristaMinima(i).first;

	}

	for(int i = 0 ; i < camino.size()-1 ; i++)

		valoracion += grafo.distancia(camino[i], camino[i+1]);

	return valoracion;

}

int explorados = 0, podas = 0;

void Backtracking::FBacktracking(int coste_actual){

	if(camino_actual.size() == grafo.size()){

		coste_actual += grafo.distancia(camino_actual.back(),camino_actual.front());

		if(coste_actual < mejor_coste){

			mejor_camino = camino_actual;
			mejor_coste = coste_actual;

		}
	}

	else if(coste_actual < mejor_coste){

		for(int hijo = 1; hijo < grafo.size(); hijo++){

			if(!EstaEn(hijo,camino_actual)){

				camino_actual.push_back(hijo);
				int coste_hijo = heuristica(camino_actual);
				explorados++;
				FBacktracking(coste_hijo);

			}
		}
	}

	else

		podas++;

	camino_actual.pop_back();

}

void Backtracking::FBacktracking(){

	FBacktracking(heuristica(camino_actual));
	cout << endl << "Nodos explorados: " << explorados << endl;
	cout << "Podas: " << podas << endl;
	
}

vector<int> Backtracking::getMejorCamino(){

	return mejor_camino;

}

int Backtracking::getMejorCoste(){

	return mejor_coste;
}