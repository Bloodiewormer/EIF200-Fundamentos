#include<iostream>
using namespace std;
bool palin;
//Se tiene un identificador string llamado palabra.  El usuario ingresa cualquier palabra por el teclado. Por ejemplo, si escribe la palabra "anona" se observa que se lee igual de izquierda a derecha como de derecha a izquierda.   Hacer una función llamada palin( ) que reciba un string y que retorne true si la palabra se lee igual de derecha a izquierda como de izquierda a derecha o false en caso contrario.
//	Nota #1: Acordarse de que usted puede, a nivel de programación, tratar un string como si fuera un vector de caracteres.   
//	Nota #2:  Acordarse también, que hay una función de C++ que devuelve el valor del tamaño de un string que se llama: size.  Es decir, sabiendo que un string es un vector de letras, se puede saber cuantas letras válidas tiene ese string ayudándose con la función size( ) así:     int cant = palabra.size().
//	Nota #3: Usted debe observar al string como un vector de caracteres que puede recorrer con una estructura iterativa.
int main(){
	string palabra;
	cout<<"Ingrese una palabra . . ";
	cin>>palabra;
	for(int q = 0;q < palabra.size();q++){
		for(int w = palabra.size()-1;w>=0;w--){
			if(palabra[w] == palabra[q]){
				palin = true;
			}
			else{
				palin = false;
			}
		}
	}
	if( palin == true )
		cout<<"Si.  Esa palabra dice lo mismo si se lee en ambas direcciones"<<endl;
	else
		cout<<"No.  Esa palabra no dice lo mismo si se lee en ambas direcciones."<<endl;
	system("pause");
	return 0;
}
	
