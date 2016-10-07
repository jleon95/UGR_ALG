#include <iostream>
#include <vector>
#include <limits>
#include "Grafo.h"

using namespace std;

const int MAX_VALUE = numeric_limits<int>::max();

int InsercionMinima(Grafo &grafo, vector<int> &circuito) {

	int nodo_candidato = 0, aumento = 0, mejor_aumento_nodo, mejor_aumento_global, pos_inserc, nodo_inserc, mejor_nodo_inserc, mejor_pos_inserc;
	vector<int> usados(grafo.size(), false);
	int recorrido = 0;
	
	//3 nodos más distantes
	
	//Nodo de partida para el triángulo: 0
	
	//Primer nodo más distante al 0.
	for (int i = 1 ; i < grafo.size() ; i++)
		
		if (grafo.distancia(0,i) > aumento) {
			
			aumento = grafo.distancia(0,i);
			nodo_candidato = i;
		}
	
	aumento = 0;
	usados[nodo_candidato] = true;
	circuito.push_back(nodo_candidato);
	
	//Segundo nodo más distante al 0.
	for (int i=0 ; i < grafo.size() ; i++)
		
		if (grafo.distancia(circuito[0],i) + grafo.distancia(0,i) > aumento
			 && !usados[i]) {
			
			aumento = grafo.distancia(circuito[0],i) + grafo.distancia(0,i);
			nodo_candidato = i;
		}
	
	aumento = 0;
	usados[nodo_candidato] = true;
	circuito.push_back(nodo_candidato);

	//Nodo más distante a los dos calculados anteriormente.
	for (int i = 0 ; i < grafo.size() ; i++)
		
		if (grafo.distancia(circuito[0],i) + grafo.distancia(circuito[1],i)
			 > aumento && !usados[i]) {
			
			aumento = grafo.distancia(circuito[0],i) + 
						grafo.distancia(circuito[1],i);
			nodo_candidato = i;
		}
	
	usados[nodo_candidato] = true;
	circuito.push_back(nodo_candidato);
	
	//Inserción de los demás nodos.

	for(int insercion = 0 ; insercion < grafo.size() - 3 ; insercion++){

		mejor_aumento_global = MAX_VALUE;

		for (int nodo = 0 ; nodo < grafo.size() ; nodo++) {
			
			if (!usados[nodo]) {
				
				mejor_aumento_nodo = MAX_VALUE;
				pos_inserc = 1;
				
				for (int posicion = 0 ; posicion < circuito.size() ; posicion++){
					
					aumento = grafo.distancia(circuito[posicion],nodo) + 
						grafo.distancia(circuito[(posicion+1)%circuito.size()],nodo) -
						 grafo.distancia(circuito[posicion],circuito[(posicion+1)%circuito.size()]);

					if (aumento < mejor_aumento_nodo) {
						
						mejor_aumento_nodo = aumento;
						pos_inserc = posicion+1;
						nodo_inserc = nodo;
					}
				}

				if(mejor_aumento_nodo < mejor_aumento_global){

					mejor_aumento_global = mejor_aumento_nodo;
					mejor_pos_inserc = pos_inserc;
					mejor_nodo_inserc = nodo_inserc;
				}
			}
		}

		//cout << "Voy a insertar " << mejor_nodo_inserc << " porque tiene aumento " << mejor_aumento_global << endl;
		//cout << "El nodo " << mejor_nodo_inserc << " está usado? " << usados[mejor_nodo_inserc] << endl;

		if (mejor_pos_inserc == circuito.size())
					
			circuito.push_back(mejor_nodo_inserc);
				
		else
			
			circuito.insert(circuito.begin()+mejor_pos_inserc,mejor_nodo_inserc);
			
		usados[mejor_nodo_inserc] = true;
	}
	
	for (int p = 0 ; p < circuito.size() ; p++)
	
		recorrido += grafo.distancia(circuito[p],circuito[(p+1)%circuito.size()]);
	
	circuito.push_back(circuito[0]);
	
	return recorrido;

}

int main (int argc, char **argv){
    
    if(argc != 2){
    
        cerr << "El funcionamiento es: bin/InsercionMinima <nombre del archivo>" << endl;
        return -1;

    }
        
    char * nombre = argv[1];

    Grafo grafo;
    vector<int> camino;

    grafo = CargarGrafo(nombre);

    clock_t before = clock();
    int recorrido = InsercionMinima(grafo, camino);
    clock_t after = clock();

    double elapsed_time = ((double)(after - before)/CLOCKS_PER_SEC);

    cout << "Camino obtenido: " << endl;

    for (int i = 0 ; i < camino.size() ; i++)

        cout << camino[i]+1 << " ";

    cout << endl;

    cout << "Recorrido total: " << recorrido << endl;
    cout << "Tiempo de ejecución: " << elapsed_time << endl;

    // Esto será para poder reordenarlos y pintarlos digo yo.

    //cout << "DIMENSION: " << g.size();
    //for(auto it=solucion.begin(); it!=solucion.end(); it++)

        //cout << endl << *it +1;
    
}