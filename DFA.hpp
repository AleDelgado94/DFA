#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <iomanip>
 
 using namespace std;
 
 class DFA
 {
 	private:
		int estado_i; //Estado inicial
		int n_e; //Numero estados
		int **estado; //Vector disperso que contendrá todos los estados al que se transita, los estados en los que se encuentra, el número de transiciones...
	
		
	public:
		DFA();
		~DFA();
		void leer_DFA(char nombre_fichero[]);
		void mostrar_DFA(void);
		void estados_muerte(void);
		void analizar_cadena();
		void menu(void);
		char estado1; //Primer elemento que se introduce para la transicion, en nuestro caso a o 0
		char estado2; //Segundo elemento que se introduce para la transicion, en nuestro caso b o 1
 	
 };
