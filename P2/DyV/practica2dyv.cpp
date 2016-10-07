#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <chrono>
#include <iomanip>
#include <algorithm>

//compilar con g++ practica2.c -o practica2 

#define umbral 3

using namespace std;

int BusquedaFB(int * & v, int ini, int fin){

	int maximo = ini;
	
	if((fin - ini) == 2 && v[ini] < v[ini+1]){

		return ini+1;

	}

	else if((fin - ini) > 1){
	
		for (int i=ini+1; i<fin; i++)

			if(v[i-1] > v[i])

				return i-1;
		
	}

	return maximo;

}

int busqueda(int * & v, const int ini, const int fin){

	int solucion;

	if((fin - ini) <= umbral)

		solucion = BusquedaFB(v,ini,fin);
	
	else{

		solucion = (fin + ini)/2;

		if(v[solucion-1] < v[solucion] && v[solucion] < v[solucion+1])

			solucion = busqueda(v,solucion+1,fin);

		else if(v[solucion-1] > v[solucion] && v[solucion] > v[solucion+1])

			solucion = busqueda(v,ini,solucion);
		
	}

	return solucion;
	
}

double uniforme() //Genera un número uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C.
{
double u;
  u = (double) rand();
  u = u/(double)(RAND_MAX+1.0);
 return u;
}

int main(int argc, char * argv[]){
	std::chrono::high_resolution_clock::time_point t_antes, t_despues, t_antes2, t_despues2;
//	clock_t t_antes, t_despues, t_antes2, t_despues2;
	int solucion; //tamaño del vector
	std::chrono::duration<double> d1,d2;

	//setprecision(10);	
		
	if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }

  	int n = atoi(argv[1]);

  	int * T = new int[n];
  	assert(T);
  	/*Codigo para generar la serie unimodal*/
	srand(time(0));
	double u=uniforme();
	int p=1+(int)((n-2)*u);
	T[p]=n-1;
	for (int i=0; i<p; i++) T[i]=i;
	for (int i=p+1; i<n; i++) T[i]=n-1-i+p;
	/****************************************/

	//cout << "Serie unimodal inicializada" << endl;
	//cout << "Umbral: " << umbral << endl;


	//t_antes=std::chrono::high_resolution_clock::now();
	//solucion = busqueda(T,0,n);
	//t_despues=std::chrono::high_resolution_clock::now();
	
	t_antes2=std::chrono::high_resolution_clock::now();
	solucion = BusquedaFB(T,0,n);
	t_despues2=std::chrono::high_resolution_clock::now();


	//d1=std::chrono::duration_cast<std::chrono::duration<double>>(t_despues-t_antes);
	d2=std::chrono::duration_cast<std::chrono::duration<double>>(t_despues2-t_antes2);
	

	//for (int j=0; j<n; j++) {cout << T[j] << " ";} cout << endl;
	//cout << n << " " << d1.count() << endl;//((double)(t_despues2 - t_antes2))/CLOCKS_PER_SEC << endl;
	cout << n << " " << d2.count() << endl;// ((double)(t_despues - t_antes))/CLOCKS_PER_SEC << endl;
	cout << "El pico de la serie unimodal es: " << T[solucion] << " en la posición " << solucion+1 << " de " << n << endl;
	
	return 0;
	
}
