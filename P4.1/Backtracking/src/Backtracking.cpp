#include <iostream>
#include <ctime>
#include <cstdlib>
#include "tda.h"

using namespace std;

int main(int argc, char **argv){

	if(argc != 3){
	
		cerr << "El funcionamiento es: bin/Backtracking <tamaño del laberinto> <semilla>" << endl;
		return -1;

	}

	int semilla = atoi(argv[2]);

	srand(semilla);
	int size = atoi(argv[1]);
	Solucion sol(size);
	
	//sol.printMaze();

	//clock_t before = clock();
	//sol.findPath();
	//clock_t after = clock();

	clock_t before = clock();
	bool path_found = sol.findBestPath();
	clock_t after = clock();

	double elapsed_time = ((double)(after - before)/CLOCKS_PER_SEC);

	if(path_found)
		sol.printSolution();
	sol.CprintMaze();

	cout << size << " " << elapsed_time << endl;
	
	return 0;

}