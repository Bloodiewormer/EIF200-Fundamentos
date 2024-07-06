#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
	//declaración de variables...
	double dato1, dato2, Resultado=0 ;
	int problema=0;
	//ENTRADA de datos....
	cout << "----------Calculadora----------"<<endl;
	cout << "Por favor Ingrese el primer dato" <<endl;
	cin >> dato1;
	cout << "Por favor ingrese el segundo dato" << endl;
	cin >> dato2;
	cout << "Selecione que tipoo de operacion decea realizar" << endl;
	cout << " 1=Suma \n 2=resta \n 3=multiplicacion \n 4=division \n 5=Potencia \n 6=Raiz" << endl;
	cin >> problema;
	cout << "---------Calculando---------" << endl;
	cout << endl;
	// Zona de calculos y resultados
	switch(problema){
	case 1:Resultado = dato1 + dato2;
		cout << "El Resultado es:" << endl;
		cout << Resultado << endl;
		cout << "\n----------Gracias---------"<<endl;
	break;
	case 2: Resultado = dato1 - dato2;
		cout << "El Resultado es:" << endl;
		cout << Resultado << endl;
		cout << "\n----------Gracias---------"<<endl;
	break;
	case 3:
	for(int i=0;i < dato2;++i){
			Resultado += dato1;
		}cout << "El Resultado es:" << endl;
		cout << Resultado << endl;
		cout << "\n----------Gracias---------"<<endl;
		// se podria usar dato1 * dato2, pero pasamos
	break;
	case 4:
		while (dato1 >= dato2){
		dato1 -= dato2;
		Resultado++;}
	if(dato2 == 0&&dato1<dato2){
		cout << "\nNo se puede mostrar el Resultado\n\n" << endl;
		cout << "-------Intente otra vez-------" << endl;
		//Hace que al incertar un cero marque como imposible en lugar de inf y evita numeros erroneos
	}else{
		cout << "El Resultado es:" << endl;
		cout << Resultado << endl;
		cout << "\n----------Gracias---------"<<endl;}
	break;
	case 5: Resultado = pow(dato1,dato2);
		cout << "El Resultado es:" << endl;
		cout << Resultado << endl;
		cout << "\n----------Gracias---------"<<endl;
	break;
	case 6: Resultado = pow(dato1,(1/dato2));
	if(dato2 == 0){
		cout << "\nImposible de calcular\n\n" << endl;
		cout << "-------Intente otra vez-------" << endl;
	}else{
		cout << "El Resultado es:" << endl;
		cout << Resultado << endl;
		cout << "\n----------Gracias---------"<<endl;}
	break;
	default: cout << "\nNumero invalido\n\n"<< endl;
		cout << "-------Intente otra vez-------" << endl;}
	return 0;
}
