#include<iostream>
#include "prestamo.h"
#include "coleccion.h"
using namespace std;

int main () {
	//-----------se crean las dos colecciones con las cuales trabajar------------------
	Coleccion cActual(100); 	// coleccion que ya posee el banco
	Coleccion cNueva(20); 		// coleccion nueva
	
	//--------datos de prueba---------------------------
	
	Prestamo p1 (100, "Vivienda",    30,     56,     2000000, 5.6,   true);  cActual.insertarObjeto(p1);
	Prestamo p2 (101, "Personal",    30,    120,     1000000, 7,     true);  cActual.insertarObjeto(p2);
	Prestamo p3 (102, "Personal",    30,     0,      1000000, 5.6,   false); cActual.insertarObjeto(p3);
	Prestamo p4 (103, "Vivienda",    30,     0,      1000000, 5.6,   false); cActual.insertarObjeto(p4);
	Prestamo p5 (104, "Personal",    30,     78,     3000000, 5.6,   false); cActual.insertarObjeto(p5);
	Prestamo p6 (105, "Salud",       50,     0,      1000000, 5.6,   false); cActual.insertarObjeto(p6);
	Prestamo p7 (106, "Vivienda",    30,     0,      9000000, 8,     false); cActual.insertarObjeto(p7);
	Prestamo p8 (107, "Automovil",   30,     90,     1000000, 5.6,   false); cActual.insertarObjeto(p8);
	Prestamo p9 (108, "Salud",       30,     25,     1000000, 5.6,   false); cActual.insertarObjeto(p9);
	Prestamo p10(109, "Personal",    30,     0,      4000000, 6,      false); cActual.insertarObjeto(p10);
	
	
	//-------- datos de prueba---------------------------
	Prestamo p11 (3050, "Vivienda",       30,    0,    4000000,  9,     false);  cNueva.insertarObjeto(p11);
	Prestamo p12 (3051, "Vivienda",       30,    40,   5000000,  7.7,   true);  cNueva.insertarObjeto(p12);
	Prestamo p13 (3052, "Automovil",      30,    0,    1000000,  5.9,   false); cNueva.insertarObjeto(p13);
	Prestamo p14 (3053, "Salud",          30,    0,    5000000,  3.5,   false); cNueva.insertarObjeto(p14);
	Prestamo p15 (3054, "Personal",       30,    47,   5000000,  6,     true);  cNueva.insertarObjeto(p15);
	Prestamo p16 (3055, "Salud",          50,    0,    1000000,  6,     false); cNueva.insertarObjeto(p16);
	Prestamo p17 (3056, "Automovil",      30,    0,    9000000,  8.6,   false); cNueva.insertarObjeto(p17);
	Prestamo p18 (3057, "Personal",       30,    0,    8000000,  5.5,   false); cNueva.insertarObjeto(p18);
	
	int opcion=1;
	
	while (opcion != 0)
	{
		cout<<endl<<endl;
		cout<< "                  Menu"<<endl;
		cout<< "    [ 1 ] Mostrar carteras  "<<endl;
		cout<< "    [ 2 ] Porcentaje en Mora de ambas carteras "<<endl;
		cout<< "    [ 3 ] Analisis adquisicion nueva cartera"<<endl;
		cout<< "    [ 4 ] Fusion de cartera "<<endl;
		cout<< "    [ 5 ] Condiciones especiales por pandemia "<<endl;
		cout<< "    [ 0 ] Salir"<<endl<<endl;		
		
		cout<< "Digite una opcion:  ";
		cin>> opcion;
		system("cls");
		switch (opcion){
		case 1:
			cout << "Cartera 1 :" << endl;
			cActual.imprimir();
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			cout << "Cartera 2 :" << endl;
			cNueva.imprimir();
			system ("pause");
			system("cls");
			break;
		case 2:
			cout << "Porcentaje cartera 1: " 
				 << cActual.porcentajeEnMora()*100 << "%" << endl;
			cout << "Porcentaje cartera 2: " 
				 << cNueva.porcentajeEnMora()*100 << "%" << endl;
			system ("pause");
			system("cls");
			break;
		case 3:
			if(cActual.esConveniente(cNueva)){
				cout << "si es beneficioso" << endl;
			}else{
				cout << "no es beneficioso" << endl;
			}
			system ("pause");
			system("cls");
			break;
		case 4:
			cActual.fusionarCartera(cNueva);
			cNueva.setCantidad(0);
			cActual.imprimir();
			system ("pause");
			system("cls");
			break;
		case 5:
			cout << "Se hicieron " << cActual.beneficionCovid() << " beneficios por covis" << endl;
			break;
		}
	}
	return 0;
}
