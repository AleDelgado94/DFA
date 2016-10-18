#include "DFA.hpp" 
 
 
 DFA::DFA()
 {
 	
 }
 
 
 
 DFA::~DFA()
 {
 };
 
 void DFA::leer_DFA(char nombre_fichero[])
 {
 	ifstream fichero;
 	fichero.open(nombre_fichero);
 	
 	if(fichero.is_open())
 	{
 	
 		
 		fichero >> n_e; // Se asigna el primer elemento a la variable numero de estados
 		fichero >> estado_i; // Variable que contiene el número de estado inicial
 		
 		for(int i=0;i<n_e;i++)
 			estado = new int *[n_e]; //Reservar espacio para el numero de estados del DFA
 			
 		for(int i=0;i<n_e;i++)
 		{
 			estado[i]= new int [5];  //Asignas espacio para guardar el resto de los datos a cada uno de los estados que se han reservado.
 			for(int j=0;j<7;j++)
 			{
 	//			estado[i][j];
 				
 				if(j<3)
                    fichero >> estado[i][j];
	         	if(j==4)
	            	fichero >> estado[i][3];  //Primera transición si es a o 0
	            if(j==6)
	                fichero >> estado[i][4]; //Segunda transicion si es b o 1
	        	if(j==3)
	        		fichero >> estado1; // a o 0
				if(j==5) 
					fichero >> estado2;	// b o 1
 			
 			}
 		}
 	}
 	else
	{
 		cout << endl <<"ERROR al cargar el fichero. Introduzca un fichero valido";
 		menu();
 	} 
 	
 }
 
 void DFA::mostrar_DFA()
 {
 	cout << endl << "--------Automata Determinista Finito--------" << endl;
 	cout << endl <<"Numero de estados: " << n_e << endl;
 	cout << endl <<"Estado inicial: " << estado_i << endl;
 	cout << endl <<"Estado  |  Final  |  Transiciones    |   Entrada/Transicion" << endl;
 	for(int i=0;i<n_e;i++)
 	{
 		for(int j=0;j<5;j++)
 		{
 		
			if(j==3)
			{
			if(estado1=='a')
 				cout << "    a  ";
 			else if(estado1=='0')
 				cout << "    0  ";
 			}
 			
 			if(j==4)
 			{
 				if(estado2=='b')
 				cout << "b  ";
 				else if(estado2=='1')
 				cout << "1  ";
 			}
 			
 		
 			cout << estado[i][j]<< "            ";
 		}
 		cout << endl;
 	}
 }
 
 void DFA::estados_muerte(void)
 {
 	int contador=0;
 	
 	for(int i=0;i<n_e;i++)
 	{
 		if(estado[i][1]==0)
 		contador++;
 	}
 	
 	if(contador!=0){
	 	cout << endl <<"Si hay estados de muerte y son: " << endl;
	 	for(int i=0; i<n_e; i++)
	 	{
	 		if(estado[i][1]==0)
	 		cout << estado[i][0] << "  ";
	 	}
 	}
 	else cout << "No existen estados de muerte en el DFA";
 }
 
 void DFA::analizar_cadena()
 {
 	char cadena[40];
 	int estado_actual=estado_i;
 	int estado_siguiente=0;
 	
 	cout << endl <<"Inserte la cadena a analizar: ";
 	cin >> cadena;
 	char *cad;
 	cad=cadena; // transformamos la cadena del tipo char en puntero
 	cout << endl << "Cadena de entrada: " << cadena << endl;
 	cout << "Estado actual       Entrada       Siguiente estado" << endl;
 	for (int i=0; i<(strlen(cad));i++)
 	{
 		
	 		if(cad[i]=='a'||cad[i]=='0')
	 		{
	 			estado_siguiente=estado[estado_actual][3];
	 			cout << "       " << estado_actual << "                "  << cad[i] << "             " << estado_siguiente << endl;
	 			estado_actual=estado_siguiente;
	 		}
	 		if(cad[i]=='b'||cad[i]=='1')
	 		{
	 			estado_siguiente=estado[estado_actual][4];
	 			cout << "       " <<estado_actual <<  "                "  << cad[i] << "             " << estado_siguiente << endl;
	 			estado_actual=estado_siguiente;
	 		}
	  		
 	}
 	cout << "La cadena esta ";
 	if(estado[estado_actual][1]==1)
 	cout << "ACEPTADA" << endl;
 	else
 	cout << "NO ACEPTADA" << endl;
 	
 }
 
 void DFA::menu()
 {
 	char opcion;
 	cout << endl<<endl;
 	cout << "--------------- DFA ----------------" << endl;
 	cout << "[1]. Leer DFA" << endl;
 	cout << "[2]. Mostrar DFA" << endl;
 	cout << "[3]. Identificar los estados de muerte" << endl;
 	cout << "[4]. Analizar cadena" << endl;
 	cout << "[5]. Salir" << endl;
 	
 	cout << "Introduzca la opcion deseada: ";
 	cin >> opcion;
 	
 
 		switch(opcion)
 		{
 			case '1': 
 				char fich[20];
			 	cout << endl <<"Introduzca el nombre del fichero que contiene el DFA: ";
			 	cin >> fich;
			 	leer_DFA(fich);
			 	cout << endl <<"Fichero cargado..." << endl;
			 	DFA();
			 	menu();
			 	break;
			case '2':
				mostrar_DFA();
				menu();
				break;
			case '3':
				estados_muerte();
				menu();
				break;
			case '4':
				analizar_cadena();
				menu();
				break;
			case '5': 
				exit(1);
				break;
			default: cout << endl <<"Opcion no soportada. Introduzca una opcion valida: "; 
				menu();
				break;
 		}
 	
 	
 }
 
 int main (void)
 {
 	DFA a;
 	
 	a.menu();
 	
 	
 }
 

