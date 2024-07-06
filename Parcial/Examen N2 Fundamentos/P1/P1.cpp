#include<iostream>
#include<string>
//#include<sstream>
using namespace std;

const int PALABRAS=10;
const int LETRAS=13;
class Encriptacion {
private:
        int mat[PALABRAS][LETRAS]; 		// define la colección de palabras cifradas
        char vec[26]; 			// define las letras del abecedario, en el orden usual
public:
Encriptacion() {
    // Llena la matriz con valores -1
    for (int i = 0; i < PALABRAS; i++) {
        for (int j = 0; j < LETRAS; j++) {
            mat[i][j] = -1;
        }
    }
    // Llena el vector con  las  letras del abecedario según el orden descrito.
      int posicion = 0;
	for(char letra = 'a'; letra <= 'z'; letra++){
		vec[posicion] = letra;
		posicion++;
	}
}

~Encriptacion() {}
void imprimir(){
	for (int palabra = 0; palabra < PALABRAS; palabra++) {
		for (int letra = 0; letra < LETRAS; letra++) {
			cout << mat[palabra][letra] << "\t";
		}
		cout << endl;
	}
}
void codificacion(string frase){
	int pos = 0;
	for (int palabra = 0; palabra < PALABRAS; palabra++) {
		for (int letra = 0; letra < LETRAS; letra++) {
			if(frase[pos] != ' ' && pos < frase.size()){
				for(int i = 0; i < 26; i++){
					if( frase[pos] == vec[i] ){
						mat[palabra][letra] = i;
					}
				}
				pos++;
			}
		}
		pos++;
	}
	imprimir();
}
void decodificacion(){
	//stringstream s;
	for (int palabra = 0; palabra < PALABRAS; palabra++) {
		for (int letra = 0; letra < LETRAS; letra++) {
			if(mat[palabra][letra] != -1){
				cout << vec[mat[palabra][letra]];
			}
		}
		cout << " ";
	}
	//return s.str();
}
//inserte aquí los métodos que faltan

};



int main() {
	Encriptacion encri;
    cout << "---------------------------" << endl;
    cout << "Ingreso  del mensaje por encriptar..." << endl;
	
	cout <<"---------si desea cambiar la frase hagalo desde el codigo en main-------------"<<endl;
	//Cambiar aqui
	string frase = "cualquier frase";//<<igrese aqui
	//Cambiar aqui

	
	cout << frase << endl;
  
    cout << "Mostrar matriz de encriptacion..." << endl;
    cout << "--------------------------------------------" << endl;
	encri.codificacion(frase);


    cout <<"El mensaje descifrado es: " << endl;
    cout << "--------------------------------------------" << endl;
	encri.decodificacion();
	cout <<"\n---------si desea cambiar la frase hagalo desde el codigo en el main-------------"<<endl;
    //system("pause");
    return 0;
}
